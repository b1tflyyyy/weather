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

#include "weatherbit-dto.hpp"

void swap(WeatherbitDTO& lhs, WeatherbitDTO& rhs) noexcept
{
    using std::swap;

    swap(lhs.mCityName, rhs.mCityName);
    swap(lhs.mCountryCode, rhs.mCountryCode);
    swap(lhs.mDaysData, rhs.mDaysData);
}

void WeatherbitDTO::DayData::FromJson(const QJsonObject& json)
{
    mWindSpeed = json.value(QStringLiteral("wind_spd")).toDouble();
    mDayHighTemp = json.value(QStringLiteral("high_temp")).toDouble();
    mDayLowTemp = json.value(QStringLiteral("low_temp")).toDouble();
    mProbabilityOfPrecipitation = json.value(QStringLiteral("pop")).toDouble();
    mCurrentTemp = json.value(QStringLiteral("temp")).toDouble();
    mSunriseTimeStamp = json.value(QStringLiteral("sunrise_ts")).toInteger();
    mSunsetTimeStamp = json.value(QStringLiteral("sunset_ts")).toInteger();
    mHumidity = json.value(QStringLiteral("rh")).toDouble();
    mVisibility = json.value(QStringLiteral("wind_spd")).toDouble();
    mDateTime = QDateTime::fromString(json.value(QStringLiteral("datetime")).toString(), "yyyy-mm-dd");

    mDateTime = mDateTime.toLocalTime();
}

void WeatherbitDTO::FromJson(const QJsonObject& json)
{
    WeatherbitDTO copy{};

    copy.mCityName = json.value(QStringLiteral("city_name")).toString();
    copy.mCountryCode = json.value(QStringLiteral("country_code")).toString();

    auto data{ json[QStringLiteral("data")].toArray() };
    copy.mDaysData.resize(std::size(data));

    for (qsizetype i{}; i < std::size(data); ++i)
    {
        copy.mDaysData[i] = QSharedPointer<DayData>::create();
        copy.mDaysData[i]->FromJson(data[i].toObject());
    }

    swap(*this, copy);
}

QSharedPointer<const WeatherbitDTO::DayData> WeatherbitDTO::GetDayData(qsizetype idx) const noexcept
{ 
    return mDaysData[idx];
}

const QString& WeatherbitDTO::GetCityName() const noexcept { return mCityName; }

const QString& WeatherbitDTO::GetCountryCode() const noexcept{ return mCountryCode; }

double WeatherbitDTO::DayData::GetWindSpeed() const noexcept { return mWindSpeed; }

double WeatherbitDTO::DayData::GetDayHighTemp() const noexcept { return mDayHighTemp; }

double WeatherbitDTO::DayData::GetDayLowTemp() const noexcept { return mDayLowTemp; }

double WeatherbitDTO::DayData::GetPOP() const noexcept { return mProbabilityOfPrecipitation; }

double WeatherbitDTO::DayData::GetCurrentTemp() const noexcept { return mCurrentTemp; }

std::int64_t WeatherbitDTO::DayData::GetSunriseTimeStamp() const noexcept { return mSunriseTimeStamp; }

std::int64_t WeatherbitDTO::DayData::GetSunsetTimeStamp() const noexcept{ return mSunsetTimeStamp; }

double WeatherbitDTO::DayData::GetHumidity() const noexcept { return mHumidity; }

double WeatherbitDTO::DayData::GetVisibility() const noexcept { return mVisibility; }

QDateTime WeatherbitDTO::DayData::GetDateTime() const noexcept{ return mDateTime; }
