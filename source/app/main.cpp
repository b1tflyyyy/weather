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
#include <model/theme/theme.hpp>
#include <model/theme-list/theme-list.hpp>
#include <model/user-config/user-config.hpp>
#include <model/forecast-card-list/forecast-card-list.hpp>

#include <controller/theme/theme.hpp>
#include <controller/animation-config/animation-config.hpp>
#include <controller/user-config/user-config.hpp>
#include <controller/forecast-card/forecast-card.hpp>

#include <internal/opengl/qml/gradient-background/gradient-background.hpp>

#include <utils/logger/logger.hpp>
#include <utils/error-handling/error-handler/error-handler.hpp>
#include <utils/error-handling/error-emitter/error-emitter.hpp>

#include <interface/ierror-emitter.hpp>

static void RegisterQMLTypes();
static void SetupFormat();

template <typename... Emitters> requires (std::is_base_of_v<IErrorEmitter, Emitters> && ...)
static void RegisterErrorEmitters(ErrorHandler* error_handler, Emitters*... error_emitter)
{
    (QObject::connect(error_emitter->GetErrorEmitter(), &ErrorEmitter::errorOccurred, error_handler, &ErrorHandler::handlerError), ...);
};

int main(int argc, char** argv)
{
    DEFAULT_LOGGER_INIT();
    DEFAULT_LOGGER_INFO("Application started...");

    SetupFormat();
    QApplication app{ argc, argv };

    ErrorHandler error_handler{};

    ThemeController theme_controller{};
    AnimationConfigController animation_config_controller{};
    UserConfigController user_config_controller{};
    ForecastCardController forecast_card_controller{};

    ThemeListModel theme_list_model{};
    ForecastCardListModel forecast_card_list_model{};

    RegisterErrorEmitters(&error_handler, 
                          &theme_controller,
                          &animation_config_controller,
                          &user_config_controller);

    QObject::connect(&theme_controller, &ThemeController::themeListLoadedSuccessfully, 
                     &theme_list_model, &ThemeListModel::themeListUpdate);
    
    QObject::connect(&forecast_card_controller, &ForecastCardController::forecastUpdated,
                     &forecast_card_list_model, &ForecastCardListModel::setForecastCards);

    QObject::connect(&user_config_controller, &UserConfigController::userConfigLoadedSuccessfully,
                     &forecast_card_controller, &ForecastCardController::userConfigUpdated);

    QObject::connect(&user_config_controller, &UserConfigController::userConfigLoadedSuccessfully,
                     &theme_list_model, &ThemeListModel::userConfigLoaded);

    theme_controller.SetPath(QStringLiteral("themes.json"));
    animation_config_controller.SetPath(QStringLiteral("animation_settings.json"));
    user_config_controller.SetPath(QStringLiteral("user_config.json"));

    theme_controller.Load();
    animation_config_controller.Load();
    user_config_controller.Load();

    QQmlApplicationEngine engine{};
    auto* ctx{ engine.rootContext() };
    
    ctx->setContextProperty(QStringLiteral("themeConfigController"), &theme_controller);
    ctx->setContextProperty(QStringLiteral("themeModel"), &theme_list_model);
    ctx->setContextProperty(QStringLiteral("animationConfigController"), &animation_config_controller);
    ctx->setContextProperty(QStringLiteral("userConfigController"), &user_config_controller);
    ctx->setContextProperty(QStringLiteral("forecastCardModel"), &forecast_card_list_model);
    ctx->setContextProperty(QStringLiteral("forecastCardController"), &forecast_card_controller);

    RegisterQMLTypes();

    const QUrl& url{ QStringLiteral("qrc:/main-window/MainWindow.qml") };
    engine.load(url);

    return QApplication::exec();
}

void RegisterQMLTypes()
{
    qmlRegisterUncreatableType<ThemeModel>("ThemeConfigModel", 1, 0, "ThemeConfigModel", "");
    qmlRegisterUncreatableType<AnimationConfigModel>("AnimationConfigModel", 1, 0, "AnimationConfigModel", "");
    qmlRegisterUncreatableType<UserConfigModel>("UserConfigModel", 1, 0, "UserConfigModel", "");

    qmlRegisterType<GradientBackgroundQml>("GradientBackgroundOpenGL", 1, 0, "GradientBackground");
}

void SetupFormat()
{
    QSurfaceFormat fmt{};
    fmt.setSwapInterval(1);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    fmt.setRenderableType(QSurfaceFormat::OpenGL);
    fmt.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    fmt.setVersion(4, 5);
    
    QSurfaceFormat::setDefaultFormat(fmt);
}