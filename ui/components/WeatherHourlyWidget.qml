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

Rectangle {
    id: _weatherHourlyWidget

    property int hour: 0
    property int degrees: 0

    property string weatherImage: ""

    radius: 30

    opacity: _mouseArea.containsMouse ? 1.0 : 0.7

    Behavior on opacity {
        NumberAnimation {
            duration: 300
            easing.type: Easing.InSine
        }
    }

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: "#ad6518"
        }

        GradientStop {
            position: 0.5
            color: "#ad188d"
        }
    }

    // border {
    //     color: "#ffffff"
    //     width: 1
    // }

    Text {
        id: _degreesText

        color: "#a6e4fc"

        anchors {
            top: parent.top
            topMargin: 20

            horizontalCenter: parent.horizontalCenter
        }

        font {
            pixelSize: parent.height * 0.20
        }

        text: "%1°".arg(degrees)
    }

    Image {
        id: _weatherImage

        height: parent.height * 0.30
        width: parent.width

        anchors {
            top: _degreesText.bottom
            topMargin: 5

            horizontalCenter: parent.horizontalCenter
        }

        mipmap: true
        smooth: true

        fillMode: Image.PreserveAspectFit

        source: _weatherHourlyWidget.weatherImage
    }

    Text {
        id: _hourText

        color: "#a6e4fc"

        anchors {
            top: _weatherImage.bottom
            topMargin: 2

            horizontalCenter: parent.horizontalCenter 
        }

        font {
            pixelSize: parent.height * 0.10
            bold: true
        }

        text: "AM %1".arg(hour)
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: parent

        hoverEnabled: true
    }
}