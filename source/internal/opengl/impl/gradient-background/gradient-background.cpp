// MIT License
// 
// Copyright (c) 2025 @Who
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "gradient-background.hpp"

GradientBackgroundImpl::GradientBackgroundImpl()
    : QQuickFramebufferObject::Renderer{}
    , QOpenGLFunctions_4_5_Core{}
{
    if (!initializeOpenGLFunctions())
    {
        DEFAULT_LOGGER_COLOR_CRITICAL(Logger::Tc::red,
                                      Logger::Tc::white,
                                      Logger::Emp::bold,
                                      "Error: failed to initialize OpenGL functions");
    }
    
    InitShaders();
    InitGeometry();

    mTimer.start();
}

GradientBackgroundImpl::~GradientBackgroundImpl() noexcept
{
    glDeleteVertexArrays(1, &mVAO);

    glDeleteBuffers(1, &mIBO);
    glDeleteBuffers(1, &mVBO);
}

void GradientBackgroundImpl::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    const float current_time = mTimer.elapsed() / 1'000.0f;
    
    mShaderProgram.bind();
    mShaderProgram.setUniformValue("u_Time", current_time);

    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

    mShaderProgram.release();
    update();
}

QOpenGLFramebufferObject* GradientBackgroundImpl::createFramebufferObject(const QSize& size)
{
    QOpenGLFramebufferObjectFormat format{};
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

    return new QOpenGLFramebufferObject{ size, format };
}

void GradientBackgroundImpl::synchronize(QQuickFramebufferObject* fbo)
{
    auto* obj{ dynamic_cast<GradientBackgroundQml*>(fbo) };

    mShaderProgram.bind();

    mShaderProgram.setUniformValue("u_Color_1", obj->GetFirstGradientColor());
    mShaderProgram.setUniformValue("u_Color_2", obj->GetSecondGradientColor());
    mShaderProgram.setUniformValue("u_Color_3", obj->GetThirdGradientColor());

    mShaderProgram.release();
}

void GradientBackgroundImpl::InitShaders()
{
    // TODO: remove hardcoded path ...
    mVertexShader = ShaderLoader::LoadShader(QStringLiteral("/home/who/weather/source/internal/opengl/impl/gradient-background/shaders/shader.vert"));
    mFragmentShader = ShaderLoader::LoadShader(QStringLiteral("/home/who/weather/source/internal/opengl/impl/gradient-background/shaders/shader.frag"));

    if (mVertexShader.isEmpty() || mFragmentShader.isEmpty()) return;
    
    if (!RegisterShader(QOpenGLShader::Vertex, mVertexShader)) return;
    if (!RegisterShader(QOpenGLShader::Fragment, mFragmentShader)) return;

    if (!mShaderProgram.link())
    {
        DEFAULT_LOGGER_COLOR_CRITICAL(Logger::Tc::red, 
                                      Logger::Tc::white,
                                      Logger::Emp::bold,
                                      "Error: failed to link shader program ->\n{}", mShaderProgram.log().toStdString());
    }
}

void GradientBackgroundImpl::InitGeometry()
{
    constexpr float positions[]
    {
    //    X      Y     Z      U      V
        -1.0f, -1.0f, 0.0f,  0.0f,  0.0f, // left-bottom
         1.0f, -1.0f, 0.0f,  1.0f,  0.0f, // right-bottom
         1.0f,  1.0f, 0.0f,  1.0f,  1.0f, // right-top
        -1.0f,  1.0f, 0.0f,  0.0f,  1.0f  // left-top
    };
    
    constexpr std::uint32_t indices[]
    {
        0, 1, 2, // first triangle
        2, 0, 3  // second triangle
    };

    constexpr auto stride{ sizeof(float) * 5 };

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<const void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

bool GradientBackgroundImpl::RegisterShader(QOpenGLShader::ShaderType type, const QString& source)
{
    if (!mShaderProgram.addCacheableShaderFromSourceCode(type, source))
    {
        DEFAULT_LOGGER_COLOR_CRITICAL(Logger::Tc::red,
                                      Logger::Tc::white,
                                      Logger::Emp::bold,
                                      "Error: failed to register {} shader ->\n{}", GetShaderTypeString(type), mShaderProgram.log().toStdString());
    
        return false;
    }

    DEFAULT_LOGGER_INFO("{} shader registered successfully", GetShaderTypeString(type));
    return true;
}

std::string_view GradientBackgroundImpl::GetShaderTypeString(QOpenGLShader::ShaderType type)
{
    switch (type) 
    {
    case QOpenGLShader::Vertex: return "Vertex";
    case QOpenGLShader::Fragment: return "Fragment";
    default: return "Undefined";
    }
}