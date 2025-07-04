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
    id: _weatherHourlyWidget

    property int hour: 0
    property int degrees: 0

    property string weatherImage: ""

    property color degreesColor
    property color timeColor 
    property color cardColor

    readonly property int themeChangingDuration: animationConfigController.animationConfig.themeChangingDuration

    Behavior on degreesColor {
        ColorAnimation {
            duration: themeChangingDuration
            easing.type: Easing.InQuint 
        }
    }

    Behavior on timeColor {
        ColorAnimation {
            duration: themeChangingDuration
            easing.type: Easing.InQuint 
        }
    }

    Behavior on cardColor {
        ColorAnimation {
            duration: themeChangingDuration
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

        anchors {
            fill: parent
        }

        Text {
            id: _degreesText

            color: degreesColor

            anchors {
                left: parent.left
                leftMargin: 20

                verticalCenter: parent.verticalCenter
            }

            font {
                pixelSize: parent.height * 0.30
            }

            text: "%1°".arg(degrees)
        }

        Image {
            id: _weatherImage

            height: parent.height * 0.30
            width: parent.width * 0.60

            anchors {
                left: _degreesText.left
                verticalCenter: parent.verticalCenter
            }

            mipmap: true
            smooth: true

            fillMode: Image.PreserveAspectFit

            source: _weatherHourlyWidget.weatherImage
        }

        Text {
            id: _hourText

            color: timeColor

            anchors {
                right: parent.right 
                rightMargin: 25

                verticalCenter: parent.verticalCenter 
            }

            font {
                pixelSize: parent.height * 0.20
                bold: true
            }

            text: "AM %1".arg(hour)
        }
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: parent

        hoverEnabled: true
    }
}