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

void swap(UserConfigModel& lhs, UserConfigModel& rhs) noexcept
{
    using std::swap;

    swap(lhs.mCity, rhs.mCity);
    swap(lhs.mThemeIndex, rhs.mThemeIndex);
    swap(lhs.mWeatherAPIToken, rhs.mWeatherAPIToken);
    swap(lhs.mUnits, rhs.mUnits);
    swap(lhs.mLatitude, rhs.mLatitude);
    swap(lhs.mLongitude, rhs.mLongitude);
}

const QString& UserConfigModel::GetCity() const noexcept { return mCity; }
const QString& UserConfigModel::GetWeatherAPIToken() const noexcept { return mWeatherAPIToken; }
const QString& UserConfigModel::GetUnits() const noexcept { return mUnits; }

double UserConfigModel::GetLatitude() const noexcept { return mLatitude; }
double UserConfigModel::GetLongitude() const noexcept { return mLongitude; }

std::size_t UserConfigModel::GetThemeIndex() const noexcept { return mThemeIndex; }

void UserConfigModel::SetThemeIndex(std::size_t idx)
{
    mThemeIndex = idx;    
}

void UserConfigModel::FromJson(const QJsonObject& json)
{
    UserConfigModel copy{};

    copy.mCity = json.value(QStringLiteral("City")).toString();
    copy.mWeatherAPIToken = json.value(QStringLiteral("WeatherAPIToken")).toString();
    copy.mThemeIndex = static_cast<std::size_t>(json.value(QStringLiteral("ThemeIndex")).toInteger());
    copy.mLatitude = json.value(QStringLiteral("Latitude")).toDouble();
    copy.mLongitude = json.value(QStringLiteral("Longitude")).toDouble();    
    copy.mUnits = json.value(QStringLiteral("Units")).toString();

    swap(*this, copy);
}

QJsonObject UserConfigModel::ToJson() const
{
    QJsonObject object{};

    object["City"] = mCity;
    object["WeatherAPIToken"] = mWeatherAPIToken;
    object["ThemeIndex"] = static_cast<qint64>(mThemeIndex);
    object["Latitude"] = mLatitude;
    object["Longitude"] = mLongitude;
    object["Units"] = mUnits;

    return object;
}