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
import QtQuick.Shapes 

Item {
    id: _themeWidget

    property string themeName: ""

    property color firstColor 
    property color secondColor 
    property color thirdColor 

    property real firstPosition: 0.0
    property real secondPosition: 0.0
    property real thirdPosition: 0.0

    property real backgroundRadius: 0

    Rectangle {
        id: _blurredBackground

        anchors {
            fill: parent
        }

        color: "#ffffff"
        clip: true

        radius: backgroundRadius

        layer {
            enabled: true
            smooth: true

            effect: MultiEffect {
                maskEnabled: true
                maskSource: _blurredBackground

                blurEnabled: true
                
                blur: 2.0
                blurMax: 32

                antialiasing: true
            }
        }
    }

    Item {
        id: _content

        anchors {
            fill: parent
        }

        Rectangle {
            id: _themeColor

            anchors {
                verticalCenter: parent.verticalCenter

                left: parent.left
                leftMargin: 10
            }

            height: parent.height * 0.40
            width: parent.height * 0.40

            radius: width * 0.5

            gradient: Gradient {
                orientation: Gradient.Horizontal

                GradientStop {
                    position: firstPosition
                    color: firstColor
                }

                GradientStop {
                    position: secondPosition
                    color: secondColor
                }

                GradientStop {
                    position: thirdPosition
                    color: thirdColor
                }
            }
        }

        Text {
            id: _themeName

            width: parent.width * 0.20
            height: parent.height * 0.40

            anchors {
                left: _themeColor.right
                leftMargin: 20

                verticalCenter: _themeColor.verticalCenter
            }

            font {
                pixelSize: parent.height * 0.30
            }

            color: "#1f1f1f"
            text: themeName
        }
    }
}