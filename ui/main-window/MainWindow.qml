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
import QtQuick.Window 2.15

import "../pages/main-page"

import "../components"

Window {
    id: _mainWindow

    visible: true
    title: qsTr("Weather")

    width: Screen.width * 0.5
    height: Screen.height * 0.5

    minimumWidth: 1000
    minimumHeight: 600

    MainPage {
        id: _mainPage
        anchors.fill: parent 

        ForecastPanel {
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
    }
}