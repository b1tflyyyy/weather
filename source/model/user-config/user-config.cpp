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

#include "user-config.hpp"

const QString& UserConfigModel::GetCity() const noexcept { return mCity; }

std::size_t UserConfigModel::GetThemeIndex() const noexcept { return mThemeIndex; }

void UserConfigModel::SetThemeIndex(std::size_t idx)
{
    mThemeIndex = idx;    
}

QSharedPointer<UserConfigModel> UserConfigModel::FromJSON(const QJsonObject& obj)
{
    auto model{ QSharedPointer<UserConfigModel>::create() };

    model->mCity = obj.value(QStringLiteral("City")).toString();
    model->mThemeIndex = static_cast<std::size_t>(obj.value(QStringLiteral("ThemeIndex")).toInteger());

    return model;
}

QByteArray UserConfigModel::ToJSON(const QSharedPointer<UserConfigModel>& cfg)
{
    QJsonObject object{};

    object["City"] = cfg->GetCity();
    object["ThemeIndex"] = static_cast<qint64>(cfg->GetThemeIndex());

    return QJsonDocument{ object }.toJson();
}