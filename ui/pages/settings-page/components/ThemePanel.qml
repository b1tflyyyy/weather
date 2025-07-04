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

ListView {
    id: _themePanel

    readonly property real scrollingSpeed: 15.0
    readonly property real itemRadius: 25

    Behavior on contentX {
        NumberAnimation {
            duration: 100
            easing.type: Easing.Linear
        }
    }

    orientation: ListView.Vertical
    spacing: 20

    cacheBuffer: 10

    boundsBehavior: Flickable.DragAndOvershootBounds

    highlight: Rectangle {
        color: "transparent"
        radius: itemRadius - 5

        border {
            width: 2
            color: "white"
        }
    }
    
    highlightFollowsCurrentItem: true

    model: themeConfigListModel

    delegate: ThemeWidget {
        height: _themePanel.height * 0.20
        width: _themePanel.width

        themeName: model.themeName

        firstColor: model.weatherBackgroundFirstColor
        secondColor: model.weatherBackgroundSecondColor
        thirdColor: model.weatherBackgroundThirdColor

        firstPosition: model.weatherBackgroundFirstColorPosition
        secondPosition: model.weatherBackgroundSecondColorPosition
        thirdPosition: model.weatherBackgroundThirdColorPosition

        backgroundRadius: _themePanel.itemRadius

        MouseArea {
            id: _mouseArea

            anchors {
                fill: parent
            }

            hoverEnabled: true

            onEntered: function () {
                _themePanel.currentIndex = index
            }

            onClicked: function (mouse) {
                themeConfigController.SetCurrentTheme(index)
            }
        }
    }

    WheelHandler {
        onWheel: function (event) {
            _themePanel.flick(0, event.angleDelta.y * _themePanel.scrollingSpeed)
        }
    }
}