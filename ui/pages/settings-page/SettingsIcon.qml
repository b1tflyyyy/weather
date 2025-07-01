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
    id: _settingsIcon 

    property int defaultWidth: 0
    property int defaultHeight: 0

    property int animatedWidth: 0
    property int animatedHeight: 0

    signal settingsClicked()

    color: "transparent"

    width: _mouseArea.containsMouse ? animatedWidth : defaultWidth
    height: _mouseArea.containsMouse ?  animatedHeight : defaultHeight 

    Behavior on width {
        NumberAnimation {
            duration: 200
            easing.type: Easing.InOutCirc
        }
    }

    Behavior on height {
        NumberAnimation {
            duration: 200
            easing.type: Easing.InOutQuad
        }
    }

    Image {
        anchors.fill: parent

        mipmap: true
        fillMode: Image.PreserveAspectFit

        source: "qrc:/assets/icons/settings.png"
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: parent

        hoverEnabled: true
        onClicked: function (mouse) {
            settingsClicked()
        }
    }
}