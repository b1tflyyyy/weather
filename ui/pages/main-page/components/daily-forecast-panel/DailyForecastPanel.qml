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
    id: _forecastPanel

    property real scrollingSpeed: 15.0

    ListModel { // for test
        id: _testForecastModel

        ListElement {
            height: 200
            width: 350
            
            weatherImage: "qrc:/assets/images/cloudy.png"
            weatherDescription: "cloudy"

            location: "Slovakia, Bratislava"
            day: "Today"

            degrees: 21

            degreesLow: 13
            degreesHigh: 32
        }

        ListElement {
            height: 200
            width: 350

            weatherImage: "qrc:/assets/images/rainy.png"
            weatherDescription: "rainy"

            location: "Slovakia, Bratislava"
            day: "Fri"

            degrees: 14

            degreesLow: 6
            degreesHigh: 22
        }

        ListElement {
            height: 200
            width: 350

            weatherImage: "qrc:/assets/images/sunny.png"
            weatherDescription: "cloudy"

            location: "Slovakia, Bratislava"
            day: "Sat"

            degrees: 27

            degreesLow: 17
            degreesHigh: 32
        }

        ListElement {
            height: 200
            width: 350

            weatherImage: "qrc:/assets/images/windy.png"
            weatherDescription: "windy"

            location: "Slovakia, Bratislava"
            day: "Sun"

            degrees: 22

            degreesLow: 19
            degreesHigh: 24
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

    model: _testForecastModel
    
    delegate: DailyWeatherWidget {
        height: _forecastPanel.height 
        width: _forecastPanel.width * 0.40

        dayColor: themeConfigController.currentTheme.dailyForecastDayColor
        degreesColor: themeConfigController.currentTheme.dailyForecastDegreesColor
        highLowDegreesColor: themeConfigController.currentTheme.dailyForecastHighLowDegreesColor
        locationColor: themeConfigController.currentTheme.dailyForecastLocationColor
        descriptionColor: themeConfigController.currentTheme.dailyForecastDescriptionColor
        cardColor: themeConfigController.currentTheme.dailyForecastCardColor

        weatherImage: model.weatherImage
        weatherDescription: model.weatherDescription

        location: model.location
        day: model.day

        degrees: model.degrees

        degreesLow: model.degreesLow
        degreesHigh: model.degreesHigh
    }

    WheelHandler {
        onWheel: function (event) {
            _forecastPanel.flick(event.angleDelta.y * _forecastPanel.scrollingSpeed, 0)
        }
    }
}