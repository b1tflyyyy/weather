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

Item {
    id: _forecastFetchingDataIndicator

    property bool showArrowDown: true

    readonly property string arrowDownImage: "qrc:/assets/icons/arrow-down.png"
    readonly property string loadingImage: "qrc:/assets/icons/loading.png"
    readonly property int animationDuration: 100    

    Behavior on width {
        NumberAnimation {
            duration: _forecastFetchingDataIndicator.animationDuration
            easing.type: Easing.OutCubic	
        }
    }

    Behavior on height {
        NumberAnimation {
            duration: _forecastFetchingDataIndicator.animationDuration
            easing.type: Easing.OutCubic	
        }
    }

    Behavior on opacity {
        NumberAnimation {
            duration: _forecastFetchingDataIndicator.animationDuration
            easing.type: Easing.OutCubic	
        }
    }    

    Image {
        id: _loadingImage

        anchors {
            fill: parent
        }

        mipmap: true
        fillMode: Image.PreserveAspectFit

        source: showArrowDown ? arrowDownImage : loadingImage

        onSourceChanged: function() {
            _loadingImage.rotation = 0
        }
    }
    
    RotationAnimator {
        id: _rotationAnimation
        target: _loadingImage

        from: 0
        to: 360

        duration: 500
        running: !showArrowDown

        loops: Animation.Infinite
    }
}