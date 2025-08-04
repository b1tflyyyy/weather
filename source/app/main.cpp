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

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSurfaceFormat>

#include <QMessageBox>

#include <model/animation-config/animation-config.hpp>
#include <model/theme-config/theme-config.hpp>
#include <model/theme-config-list/theme-config-list.hpp>
#include <model/user-config/user-config.hpp>

#include <controller/theme-config/theme-config.hpp>
#include <controller/animation-config/animation-config.hpp>
#include <controller/user-config/user-config.hpp>

#include <internal/opengl/qml/gradient-background/gradient-background.hpp>

#include <utils/logger/logger.hpp>

static void RegisterQMLTypes();
static void SetupFormat();

int main(int argc, char** argv)
{
    DEFAULT_LOGGER_INIT();
    DEFAULT_LOGGER_INFO("Application started...");

    SetupFormat();
    QApplication app{ argc, argv };

    ThemeConfigController theme_config_controller{};
    AnimationConfigController animation_config_controller{};
    UserConfigController user_config_controller{ QStringLiteral("user_config.json") };

    try 
    {
        theme_config_controller.LoadThemes(QStringLiteral("themes.json"));
        animation_config_controller.LoadAnimationSettings(QStringLiteral("animation_settings.json"));
        user_config_controller.LoadUserConfig();
    }
    catch (const std::runtime_error& e)
    {
        const std::string& error_message{ std::format("Error: {}", e.what()) };

        DEFAULT_LOGGER_COLOR_CRITICAL(Logger::Tc::red,
                                      Logger::Tc::white,
                                      Logger::Emp::bold, 
                                      "{}", error_message.c_str());

        QMessageBox message_box{};
        message_box.setWindowTitle(QStringLiteral("Critical Error"));
        message_box.setText(QString{ error_message.c_str() });
        message_box.setDefaultButton(QMessageBox::Ok);
        message_box.setIcon(QMessageBox::Critical);
        
        message_box.exec();
        
        return -1;
    }

    auto* user_config_model{ dynamic_cast<UserConfigModel*>(user_config_controller.GetUserConfig()) };
    theme_config_controller.SetCurrentTheme(user_config_model->GetThemeIndex());

    ThemeConfigListModel theme_config_list_model{ theme_config_controller.GetThemes() };

    QQmlApplicationEngine engine{};
    auto* ctx{ engine.rootContext() };
    
    ctx->setContextProperty(QStringLiteral("themeConfigController"), &theme_config_controller);
    ctx->setContextProperty(QStringLiteral("themeConfigListModel"), &theme_config_list_model);
    ctx->setContextProperty(QStringLiteral("animationConfigController"), &animation_config_controller);
    ctx->setContextProperty(QStringLiteral("userConfigController"), &user_config_controller);

    RegisterQMLTypes();

    const QUrl& url{ QStringLiteral("qrc:/main-window/MainWindow.qml") };
    engine.load(url);

    return QApplication::exec();
}

void RegisterQMLTypes()
{
    qmlRegisterUncreatableType<ThemeConfigModel>("ThemeConfigModel", 1, 0, "ThemeConfigModel", "");
    qmlRegisterUncreatableType<AnimationConfigModel>("AnimationConfigModel", 1, 0, "AnimationConfigModel", "");
    qmlRegisterUncreatableType<UserConfigModel>("UserConfigModel", 1, 0, "UserConfigModel", "");

    qmlRegisterType<GradientBackgroundQml>("GradientBackgroundOpenGL", 1, 0, "GradientBackground");
}

void SetupFormat()
{
    QSurfaceFormat fmt{};
    fmt.setSwapInterval(1);
    fmt.setRenderableType(QSurfaceFormat::OpenGL);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    fmt.setVersion(4, 5);
    
    QSurfaceFormat::setDefaultFormat(fmt);
}