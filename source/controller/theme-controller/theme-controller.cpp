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

#include "theme-controller.hpp"

ThemeController::ThemeController(QObject* parent)
    : QObject{ parent }
    , mCurrentThemeIndex{}
{ }

void ThemeController::LoadThemes(const QString& path)
{
    QFile file{ path };
    if (!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error{ "failed to open themes file" };
    }

    QByteArray data{ file.readAll() };
    file.close();

    QJsonParseError err{};
    auto doc{ QJsonDocument::fromJson(data, &err) };
    
    if (err.error != QJsonParseError::NoError)
    {
        throw std::runtime_error{ "failed to parse json" };
    }
    if (!doc.isArray())
    {
        throw std::runtime_error{ "json is not an array" };
    }

    QJsonArray json_arr{ doc.array() };
    
    QVector<QSharedPointer<ThemeModel>> copy{};
    copy.reserve(json_arr.size());

    for (const auto& el : json_arr)
    {
        copy.push_back(ThemeModel::FromJSON(el.toObject()));
    }

    std::swap(copy, mThemes);
}

QObject* ThemeController::GetCurrentTheme() { return mThemes[mCurrentThemeIndex].data(); }

void ThemeController::SetCurrentTheme(qsizetype index)
{
    if (mCurrentThemeIndex != index)
    {
        mCurrentThemeIndex = index;
        emit currentThemeChanged();
    }
}

const QVector<QSharedPointer<ThemeModel>>& ThemeController::GetThemes() const noexcept { return mThemes; }