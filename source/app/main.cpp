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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSurfaceFormat>

#include <model/animation-config/animation-config.hpp>
#include <model/theme-config/theme-config.hpp>
#include <model/theme-config-list/theme-config-list.hpp>

#include <controller/theme-config/theme-config.hpp>
#include <controller/animation-config/animation-config.hpp>

#include <internal/opengl/qml/gradient-background/gradient-background.hpp>

static void RegisterQMLTypes();
static void SetupFormat();

int main(int argc, char** argv)
{
    SetupFormat();

    ThemeConfigController theme_config_controller{};
    AnimationConfigController animation_config_controller{};

    try 
    {
        theme_config_controller.LoadThemes(QStringLiteral("themes.json"));
        animation_config_controller.LoadAnimationSettings(QStringLiteral("animation_settings.json"));
    }
    catch (const std::runtime_error& e)
    {
        qDebug() << e.what() << '\n';
    }

    ThemeConfigListModel theme_config_list_model{ theme_config_controller.GetThemes() };

    QGuiApplication app{ argc, argv };
    QQmlApplicationEngine engine{};

    auto* ctx{ engine.rootContext() };
    
    ctx->setContextProperty(QStringLiteral("themeConfigController"), &theme_config_controller);
    ctx->setContextProperty(QStringLiteral("themeConfigListModel"), &theme_config_list_model);
    ctx->setContextProperty(QStringLiteral("animationConfigController"),  &animation_config_controller);

    RegisterQMLTypes();

    const QUrl& url{ QStringLiteral("qrc:/main-window/MainWindow.qml") };
    engine.load(url);

    return QGuiApplication::exec();
}

void RegisterQMLTypes()
{
    qmlRegisterUncreatableType<ThemeConfigModel>("ThemeConfigModel", 1, 0, "ThemeConfigModel", "");
    qmlRegisterUncreatableType<AnimationConfigModel>("AnimationConfigModel", 1, 0, "AnimationConfigModel", "");

    qmlRegisterType<GradientBackgroundQml>("GradientBackgroundOpenGL", 1, 0, "GradientBackground");
}

void SetupFormat()
{
    QSurfaceFormat fmt{};
    fmt.setSwapInterval(1);
    fmt.setRenderableType(QSurfaceFormat::OpenGL);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    fmt.setVersion(4, 5);
    fmt.setRedBufferSize(16);
    fmt.setGreenBufferSize(16);
    fmt.setBlueBufferSize(16);
    
    QSurfaceFormat::setDefaultFormat(fmt);
}