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

#include "gradient-background.hpp"

GradientBackgroundQml::GradientBackgroundQml()
    : QQuickFramebufferObject{}
{ }

GradientBackgroundQml::Renderer* GradientBackgroundQml::createRenderer() const
{
    return new GradientBackgroundImpl{};
} 

void GradientBackgroundQml::SetFirstGradientColor(const QVector3D& value)
{
    if (mFirstGradientColor != value)
    {
        mFirstGradientColor = value;
        emit firstColorChanged();

        update();
    }
}

void GradientBackgroundQml::SetSecondGradientColor(const QVector3D& value)
{
    if (mSecondGradientColor != value)
    {
        mSecondGradientColor = value;
        emit secondColorChanged();
    
        update();
    }
}

void GradientBackgroundQml::SetThirdGradientColor(const QVector3D& value)
{
    if (mThirdGradientColor != value)
    {
        mThirdGradientColor = value;
        emit thirdColorChanged();

        update();
    }
}   

const QVector3D& GradientBackgroundQml::GetFirstGradientColor() const noexcept { return mFirstGradientColor; }
const QVector3D& GradientBackgroundQml::GetSecondGradientColor() const noexcept { return mSecondGradientColor; }
const QVector3D& GradientBackgroundQml::GetThirdGradientColor() const noexcept { return mThirdGradientColor; }