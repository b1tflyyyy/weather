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

import QtQuick 2.15
import QtQuick.Effects

import "../settings-page"

import "components/daily-forecast-panel"
import "components/hourly-forecast-panel"

import GradientBackgroundOpenGL 1.0

Rectangle {
    id: _mainPage

    property color firstBackgroundGradientColor: themeConfigController.currentTheme.weatherBackgroundFirstGradientColor
    property color secondBackgroundGradientColor: themeConfigController.currentTheme.weatherBackgroundSecondGradientColor
    property color thirdBackgroundGradientColor: themeConfigController.currentTheme.weatherBackgroundThirdGradientColor

    readonly property int themeChangingDuration: animationConfigController.animationConfig.themeChangingDuration
    
    Behavior on firstBackgroundGradientColor {
        ColorAnimation {
            duration: themeChangingDuration
            easing.type: Easing.InQuint 
        }
    }

    Behavior on secondBackgroundGradientColor {
        ColorAnimation {
            duration: themeChangingDuration
            easing.type: Easing.InQuint 
        }
    }

    Behavior on thirdBackgroundGradientColor {
        ColorAnimation {
            duration: themeChangingDuration
            easing.type: Easing.InQuint 
        }
    }

    GradientBackground {
        id: _gradientBackground
        anchors.fill: parent

        firstGradientColor: Qt.vector3d(firstBackgroundGradientColor.r, firstBackgroundGradientColor.g, firstBackgroundGradientColor.b)
        secondGradientColor: Qt.vector3d(secondBackgroundGradientColor.r, secondBackgroundGradientColor.g, secondBackgroundGradientColor.b)
        thirdGradientColor: Qt.vector3d(thirdBackgroundGradientColor.r, thirdBackgroundGradientColor.g, thirdBackgroundGradientColor.b)
    }

    DailyForecastPanel {
        id: _forecastPanel

        height: parent.height * 0.40
        width: parent.width

        anchors {
            top: parent.top
            topMargin: 20

            left: parent.left
            leftMargin: 10

            right: parent.right
            rightMargin: 10
        }
    }
    
    HourlyForecastPanel {
        id: _hourlyForecastPanel

        height: parent.height * 0.20
        width: parent.width

        anchors {
            top: _forecastPanel.bottom
            topMargin: 20

            left: _forecastPanel.left
            right: _forecastPanel.right
        }
    }

    SettingsPage {
        id: _settingsPanel
    }

    SettingsIcon {
        id: _settingsIcon

        defaultWidth: 32
        defaultHeight: 32

        animatedWidth: 36
        animatedHeight: 36

        anchors {
            right: parent.right
            rightMargin: 30

            bottom: parent.bottom
            bottomMargin: 30
        }

        onSettingsClicked: function() {
            _settingsPanel.open()
        }
    }
}