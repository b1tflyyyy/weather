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
#include <QString>
#include <QSharedPointer>

#include <QJsonDocument>
#include <QJsonObject>

#include <interface/isjon-serializable.hpp>

class UserConfigModel 
    : public QObject
    , public IToJson
    , public IFromJson 
{
    Q_OBJECT

    Q_PROPERTY(QString city READ GetCity CONSTANT);
    Q_PROPERTY(std::size_t themeIndex READ GetThemeIndex WRITE SetThemeIndex);

public:
    friend void swap(UserConfigModel& lhs, UserConfigModel& rhs) noexcept;

public:
    UserConfigModel() = default;

    const QString& GetCity() const noexcept;
    const QString& GetWeatherAPIToken() const noexcept;
    const QString& GetUnits() const noexcept;
    
    double GetLatitude() const noexcept;
    double GetLongitude() const noexcept;
    
    std::size_t GetThemeIndex() const noexcept;
    void SetThemeIndex(std::size_t idx);

    void FromJson(const QJsonObject& json) override;
    QJsonObject ToJson() const override;

private:
    QString mCity;
    QString mWeatherAPIToken;
    QString mUnits;
    double mLongitude;
    double mLatitude;
    std::size_t mThemeIndex;
};