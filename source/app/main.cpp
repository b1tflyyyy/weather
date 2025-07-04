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

#include <model/theme-list-model/theme-list-model.hpp>
#include <model/animation-speed-model/animation-speed-model.hpp>

#include <controller/animation-speed-controller/animation-speed-controller.hpp>
#include <controller/theme-controller/theme-controller.hpp>

int main(int argc, char** argv)
{
    ThemeController theme_controller{};
    AnimationSpeedController animation_speed_controller{};

    try 
    {
        theme_controller.LoadThemes(QStringLiteral("themes.json"));
        animation_speed_controller.LoadAnimationSettings(QStringLiteral("animation_settings.json"));
    }
    catch (const std::runtime_error& e)
    {
        qDebug() << e.what() << '\n';
    }

    ThemeListModel theme_list_model{ theme_controller.GetThemes() };

    QGuiApplication app{ argc, argv };
    QQmlApplicationEngine engine{};

    auto* ctx{ engine.rootContext() };
    
    ctx->setContextProperty(QStringLiteral("themeController"), &theme_controller);
    ctx->setContextProperty(QStringLiteral("themeListModel"), &theme_list_model);
    ctx->setContextProperty(QStringLiteral("animationSpeedController"),  &animation_speed_controller);

    qmlRegisterUncreatableType<ThemeModel>("ThemeModel", 1, 0, "ThemeModel", "");
    qmlRegisterUncreatableType<AnimationSpeedModel>("AnimationSpeedModel", 1, 0, "AnimationSpeedModel", "");

    const QUrl& url{ QStringLiteral("qrc:/main-window/MainWindow.qml") };
    engine.load(url);

    return QGuiApplication::exec();
}