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
import QtQuick.Controls

ListView {
    id: _hourlyForecastPanel

    property real scrollingSpeed: 15.0

    ListModel { // for test
        id: _testHourlyForecastModel

        ListElement {
            height: 200
            width: 80

            hour: 00
            degrees: 13

            weatherImage: "qrc:/assets/images/cloudy.png"
        }

        ListElement {
            height: 200
            width: 80

            hour: 03
            degrees: 15

            weatherImage: "qrc:/assets/images/cloudy.png"
        }

        ListElement {
            height: 200
            width: 80

            hour: 06
            degrees: 16

            weatherImage: "qrc:/assets/images/sunny.png"
        }

        ListElement {
            height: 200
            width: 80

            hour: 09
            degrees: 20

            weatherImage: "qrc:/assets/images/rainy.png"
        }

        ListElement {
            height: 200
            width: 80

            hour: 12
            degrees: 17

            weatherImage: "qrc:/assets/images/windy.png"
        }

        ListElement {
            height: 200
            width: 80

            hour: 15
            degrees: 14

            weatherImage: "qrc:/assets/images/windy.png"
        }
    } // for test

    Behavior on contentX {
        NumberAnimation {
            duration: 100
            easing.type: Easing.Linear
        }
    }

    orientation: ListView.Horizontal
    spacing: 20

    cacheBuffer: 7

    boundsBehavior: Flickable.DragAndOvershootBounds

    model: _testHourlyForecastModel

    delegate: WeatherHourlyWidget {
        width: _hourlyForecastPanel.width * 0.30
        height: _hourlyForecastPanel.height

        hour: model.hour
        degrees: model.degrees

        weatherImage: model.weatherImage
    }

    WheelHandler {
        onWheel: function (event) {
            _hourlyForecastPanel.flick(event.angleDelta.y * _hourlyForecastPanel.scrollingSpeed, 0)
        }
    }

    layer {
        enabled: true
    }
}