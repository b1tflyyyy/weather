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

#include <internal/opengl/impl/gradient-background/gradient-background.hpp>

class GradientBackgroundQml : public QQuickFramebufferObject
{
    Q_OBJECT

    Q_PROPERTY(QVector3D firstGradientColor READ GetFirstGradientColor WRITE SetFirstGradientColor NOTIFY firstColorChanged);
    Q_PROPERTY(QVector3D secondGradientColor READ GetSecondGradientColor WRITE SetSecondGradientColor NOTIFY secondColorChanged);
    Q_PROPERTY(QVector3D thirdGradientColor READ GetThirdGradientColor WRITE SetThirdGradientColor NOTIFY thirdColorChanged);

public:
    GradientBackgroundQml();
    Renderer* createRenderer() const override;

    void SetFirstGradientColor(const QVector3D& value);
    void SetSecondGradientColor(const QVector3D& value);
    void SetThirdGradientColor(const QVector3D& value);

    const QVector3D& GetFirstGradientColor() const noexcept;
    const QVector3D& GetSecondGradientColor() const noexcept;
    const QVector3D& GetThirdGradientColor() const noexcept;

signals:
    void firstColorChanged();
    void secondColorChanged();
    void thirdColorChanged();

private:
    QVector3D mFirstGradientColor;
    QVector3D mSecondGradientColor;
    QVector3D mThirdGradientColor;
};