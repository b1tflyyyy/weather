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

void swap(ThemeConfigModel& lhs, ThemeConfigModel& rhs) noexcept
{
    std::swap(lhs.mThemeName, rhs.mThemeName);

    std::swap(lhs.mDailyForecastDayColor, rhs.mDailyForecastDayColor);
    std::swap(lhs.mDailyForecastDegreesColor, rhs.mDailyForecastDegreesColor);
    std::swap(lhs.mDailyForecastHighLowDegreesColor, rhs.mDailyForecastHighLowDegreesColor);
    std::swap(lhs.mDailyForecastLocationColor, rhs.mDailyForecastLocationColor);
    std::swap(lhs.mDailyForecastDescriptionColor, rhs.mDailyForecastDescriptionColor);
    std::swap(lhs.mDailyForecastCardColor, rhs.mDailyForecastCardColor);

    std::swap(lhs.mHourlyForecastDegreesColor, rhs.mHourlyForecastDegreesColor);
    std::swap(lhs.mHourlyForecastTimeColor, rhs.mHourlyForecastTimeColor);
    std::swap(lhs.mHourlyForecastCardColor, rhs.mHourlyForecastCardColor);

    std::swap(lhs.mWeatherBackgroundFirstGradientColor, rhs.mWeatherBackgroundFirstGradientColor);
    std::swap(lhs.mWeatherBackgroundSecondGradientColor, rhs.mWeatherBackgroundSecondGradientColor);
    std::swap(lhs.mWeatherBackgroundThirdGradientColor, rhs.mWeatherBackgroundThirdGradientColor);
}

QString ThemeConfigModel::GetThemeName() const noexcept { return mThemeName; }

QColor ThemeConfigModel::GetDailyForecastDayColor() const noexcept { return mDailyForecastDayColor; }
QColor ThemeConfigModel::GetDailyForecastDegreesColor() const noexcept { return mDailyForecastDegreesColor; }
QColor ThemeConfigModel::GetDailyForecastHighLowDegreesColor() const noexcept { return mDailyForecastHighLowDegreesColor; }
QColor ThemeConfigModel::GetDailyForecastLocationColor() const noexcept { return mDailyForecastLocationColor; }
QColor ThemeConfigModel::GetDailyForecastDescriptionColor() const noexcept { return mDailyForecastDescriptionColor; }
QColor ThemeConfigModel::GetDailyForecastCardColor() const noexcept { return mDailyForecastCardColor; }

QColor ThemeConfigModel::GetHourlyForecastDegreesColor() const noexcept { return mHourlyForecastDegreesColor; }
QColor ThemeConfigModel::GetHourlyForecastTimeColor() const noexcept { return mHourlyForecastTimeColor; }
QColor ThemeConfigModel::GetHourlyForecastCardColor() const noexcept { return mHourlyForecastCardColor; }

QColor ThemeConfigModel::GetWeatherBackgroundFirstGradientColor() const noexcept { return mWeatherBackgroundFirstGradientColor; }
QColor ThemeConfigModel::GetWeatherBackgroundSecondGradientColor() const noexcept { return mWeatherBackgroundSecondGradientColor; }
QColor ThemeConfigModel::GetWeatherBackgroundThirdGradientColor() const noexcept { return mWeatherBackgroundThirdGradientColor; }

void ThemeConfigModel::FromJson(const QJsonObject& json)
{
    ThemeConfigModel copy{};

    copy.mThemeName = json.value(QStringLiteral("ThemeName")).toString();

    copy.mDailyForecastDayColor = json.value(QStringLiteral("DailyForecastDayColor")).toString();
    copy.mDailyForecastDegreesColor = json.value(QStringLiteral("DailyForecastDegreesColor")).toString();
    copy.mDailyForecastHighLowDegreesColor = json.value(QStringLiteral("DailyForecastHighLowDegreesColor")).toString();
    copy.mDailyForecastLocationColor = json.value(QStringLiteral("DailyForecastLocationColor")).toString();
    copy.mDailyForecastDescriptionColor = json.value(QStringLiteral("DailyForecastDescriptionColor")).toString();
    copy.mDailyForecastCardColor = json.value(QStringLiteral("DailyForecastCardColor")).toString();

    copy.mHourlyForecastDegreesColor = json.value(QStringLiteral("HourlyForecastDegreesColor")).toString();
    copy.mHourlyForecastTimeColor = json.value(QStringLiteral("HourlyForecastTimeColor")).toString();
    copy.mHourlyForecastCardColor = json.value(QStringLiteral("HourlyForecastCardColor")).toString();

    copy.mWeatherBackgroundFirstGradientColor = json.value(QStringLiteral("WeatherBackgroundFirstGradientColor")).toString();
    copy.mWeatherBackgroundSecondGradientColor = json.value(QStringLiteral("WeatherBackgroundSecondGradientColor")).toString();
    copy.mWeatherBackgroundThirdGradientColor = json.value(QStringLiteral("WeatherBackgroundThirdGradientColor")).toString();

    swap(*this, copy);
}