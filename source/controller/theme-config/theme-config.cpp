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

#include "theme-config.hpp"

void ThemeConfigController::LoadThemes(const QString& path)
{
    auto array{ ReadJsonArray(path) };
    mThemeConfigs.resize(std::size(array));

    for (std::size_t i{}; i < std::size(array); ++i)
    {
        mThemeConfigs[i] = QSharedPointer<ThemeConfigModel>::create();
        mThemeConfigs[i]->FromJson(array[i].toObject());
    }
}

QObject* ThemeConfigController::GetCurrentTheme() 
{ 
    return dynamic_cast<QObject*>(mThemeConfigs[mCurrentThemeIndex].data()); 
}

void ThemeConfigController::SetCurrentTheme(std::size_t index)
{
    if (mCurrentThemeIndex != index)
    {
        mCurrentThemeIndex = (static_cast<qsizetype>(index) >= mThemeConfigs.size() ? 0 : index);
        emit currentThemeChanged();
    }
}

const QVector<QSharedPointer<ThemeConfigModel>>& ThemeConfigController::GetThemes() const noexcept { return mThemeConfigs; }