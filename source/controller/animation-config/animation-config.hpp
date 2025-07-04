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

#pragma once

#include <QObject>

#include <QJsonDocument>
#include <QFile>

#include <model/animation-config/animation-config.hpp>

class AnimationConfigController : public QObject
{
    Q_OBJECT 

    Q_PROPERTY(QObject* animationConfig READ GetAnimationSpeed CONSTANT);

public:
    AnimationConfigController() = default;
    ~AnimationConfigController() noexcept override = default;

    AnimationConfigController(const AnimationConfigController&) = delete;
    AnimationConfigController& operator=(const AnimationConfigController&) = delete;

    AnimationConfigController(AnimationConfigController&&) = delete;
    AnimationConfigController& operator=(AnimationConfigController&&) = delete;

    void LoadAnimationSettings(const QString& path);
    QObject* GetAnimationSpeed();

private:
    QSharedPointer<AnimationConfigModel> mAnimationSpeedModel;
};