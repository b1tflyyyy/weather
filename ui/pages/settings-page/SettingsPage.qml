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
import QtQuick.Effects

import "components"

Drawer {
    id: _settingsPage

    height: parent.height
    width: parent.width * 0.80

    edge: Qt.LeftEdge
    closePolicy: Popup.CloseOnPressOutside

    background: Rectangle {
        id: _blurredBackground

        color: "#7d7d7d"
        clip: true

        opacity: 0.5

        layer {
            enabled: true
            smooth: true

            effect: MultiEffect {
                maskEnabled: true
                maskSource: _blurredBackground

                blurEnabled: true
                
                blur: 1.0
                blurMax: 32

                antialiasing: true
            }
        }
    }

    ThemePanel {
        id: _themePanel

        height: parent.height * 0.80
        width: parent.width * 0.40

        anchors {
            right: parent.right
            rightMargin: 30

            top: parent.top
            topMargin: 20
        }
    }
}