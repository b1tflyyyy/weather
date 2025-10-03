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

#include <cstdint>

#include <interface/isjon-serializable.hpp>

class WeatherbitDTO
    : public IFromJson
{
public:
    class DayData
        : public IFromJson
    {
    public:
        void FromJson(const QJsonObject& json) override;

        double GetWindSpeed() const noexcept;
        double GetDayHighTemp() const noexcept;
        double GetDayLowTemp() const noexcept;
        double GetPOP() const noexcept;
        double GetCurrentTemp() const noexcept;
        std::int64_t GetSunriseTimeStamp() const noexcept;
        std::int64_t GetSunsetTimeStamp() const noexcept;
        double GetHumidity() const noexcept;
        double GetVisibility() const noexcept;
        QDateTime GetDateTime() const noexcept;

    private:
        double mWindSpeed;
        double mDayHighTemp;
        double mDayLowTemp;
        double mProbabilityOfPrecipitation;
        double mCurrentTemp;
        std::int64_t mSunriseTimeStamp;
        std::int64_t mSunsetTimeStamp;
        double mHumidity;
        double mVisibility;
        QDateTime mDateTime;
    };

public:
    friend void swap(WeatherbitDTO& lhs, WeatherbitDTO& rhs) noexcept;
    void FromJson(const QJsonObject& json) override;

    QSharedPointer<const DayData> GetDayData(qsizetype idx) const noexcept;

    const QString& GetCityName() const noexcept;
    const QString& GetCountryCode() const noexcept;

private:
    QString mCityName;
    QString mCountryCode;

    QVector<QSharedPointer<DayData>> mDaysData;
};