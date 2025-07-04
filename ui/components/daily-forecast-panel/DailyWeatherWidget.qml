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

Item {
    id: _weatherWidget

    property string weatherImage: ""
    property string weatherDescription: ""

    property string location: ""
    property string day: ""
    
    property int degrees: 0
    
    property int degreesLow: -100
    property int degreesHigh: 100

    property color dayColor
    property color degreesColor
    property color highLowDegreesColor
    property color locationColor
    property color descriptionColor
    property color cardColor 

    Behavior on dayColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Behavior on degreesColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Behavior on highLowDegreesColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Behavior on locationColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Behavior on descriptionColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Behavior on cardColor {
        ColorAnimation {
            duration: 2000
            easing.type: Easing.InQuint 
        }
    }

    Rectangle {
        id: _blurredBackground

        anchors {
            fill: parent
        }

        radius: 20
        clip: true

        color: cardColor
        opacity: _mouseArea.containsMouse ? 0.6 : 0.4

        Behavior on opacity {
            NumberAnimation {
                duration: 400
                easing.type: Easing.Linear
            }
        }

        layer {
            enabled: true
            smooth: true

            effect: MultiEffect {
                maskEnabled: true
                maskSource: _blurredBackground

                blurEnabled: true
                blur: 2.0

                antialiasing: true
            }
        }
    }

    Item {
        id: _cardInfo

        anchors.fill: parent

        Image {
            id: _weatherImage

            height: parent.height * 0.60
            width: parent.width * 0.30

            anchors {
                top: parent.top
                topMargin: 30

                right: parent.right
                rightMargin: 30
            }

            mipmap: true
            fillMode: Image.PreserveAspectFit

            source: _weatherWidget.weatherImage
        }

        Text {
            id: _dayText

            height: parent.height * 0.10
            width: parent.width * 0.10

            color: dayColor

            anchors {
                top: parent.top
                topMargin: 10

                left: parent.left
                leftMargin: 30
            }

            font {
                pixelSize: parent.height * 0.08
            }

            text: day
        }

        Text {
            id: _degreesText

            height: parent.height * 0.50
            width: parent.width * 0.30

            color: degreesColor

            anchors {
                top: parent.top
                topMargin: 20

                left: parent.left
                leftMargin: 20
            }

            font {
                pixelSize: parent.height * 0.40
            }

            text: "%1°".arg(degrees)
        }

        Text {
            id: _highLowTemperatureText

            height: parent.height * 0.10
            width: parent.width * 0.15

            color: highLowDegreesColor

            anchors {
                top: _degreesText.bottom
                topMargin: 10

                left: parent.left
                leftMargin: 20
            }

            font {
                pixelSize: parent.height * 0.08
            }

            text: "H:%1° L:%2°".arg(degreesHigh).arg(degreesLow)
        }

        Text {
            id: _locationText

            height: parent.height * 0.10
            width: parent.width * 0.15

            color: locationColor

            anchors {
                top: _highLowTemperatureText.bottom
                left: _highLowTemperatureText.left
            }

            font {
                pixelSize: parent.height * 0.10
            }

            text: location
        }

        Text {
            id: _weatherDescriptionText

            height: parent.height * 0.05
            width: parent.width * 0.15

            color: descriptionColor

            anchors {
                top: _weatherImage.bottom
                topMargin: 2

                right: parent.right
                rightMargin: 20
            }

            font {
                pixelSize: parent.height * 0.08
            }

            text: weatherDescription
        }
    }

    MouseArea {
        id: _mouseArea

        anchors.fill: parent
        hoverEnabled: true
    }
}