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

#include "theme.hpp"

void swap(ThemeModel& lhs, ThemeModel& rhs) noexcept
{
    using std::swap;

    swap(lhs.mThemeName, rhs.mThemeName);

    swap(lhs.mDailyForecastDayColor, rhs.mDailyForecastDayColor);
    swap(lhs.mDailyForecastDegreesColor, rhs.mDailyForecastDegreesColor);
    swap(lhs.mDailyForecastHighLowDegreesColor, rhs.mDailyForecastHighLowDegreesColor);
    swap(lhs.mDailyForecastLocationColor, rhs.mDailyForecastLocationColor);
    swap(lhs.mDailyForecastDescriptionColor, rhs.mDailyForecastDescriptionColor);
    swap(lhs.mDailyForecastCardColor, rhs.mDailyForecastCardColor);

    swap(lhs.mHourlyForecastDegreesColor, rhs.mHourlyForecastDegreesColor);
    swap(lhs.mHourlyForecastTimeColor, rhs.mHourlyForecastTimeColor);
    swap(lhs.mHourlyForecastCardColor, rhs.mHourlyForecastCardColor);

    swap(lhs.mWeatherBackgroundFirstGradientColor, rhs.mWeatherBackgroundFirstGradientColor);
    swap(lhs.mWeatherBackgroundSecondGradientColor, rhs.mWeatherBackgroundSecondGradientColor);
    swap(lhs.mWeatherBackgroundThirdGradientColor, rhs.mWeatherBackgroundThirdGradientColor);
}

QString ThemeModel::GetThemeName() const noexcept { return mThemeName; }

QColor ThemeModel::GetDailyForecastDayColor() const noexcept { return mDailyForecastDayColor; }
QColor ThemeModel::GetDailyForecastDegreesColor() const noexcept { return mDailyForecastDegreesColor; }
QColor ThemeModel::GetDailyForecastHighLowDegreesColor() const noexcept { return mDailyForecastHighLowDegreesColor; }
QColor ThemeModel::GetDailyForecastLocationColor() const noexcept { return mDailyForecastLocationColor; }
QColor ThemeModel::GetDailyForecastDescriptionColor() const noexcept { return mDailyForecastDescriptionColor; }
QColor ThemeModel::GetDailyForecastCardColor() const noexcept { return mDailyForecastCardColor; }

QColor ThemeModel::GetHourlyForecastDegreesColor() const noexcept { return mHourlyForecastDegreesColor; }
QColor ThemeModel::GetHourlyForecastTimeColor() const noexcept { return mHourlyForecastTimeColor; }
QColor ThemeModel::GetHourlyForecastCardColor() const noexcept { return mHourlyForecastCardColor; }

QColor ThemeModel::GetWeatherBackgroundFirstGradientColor() const noexcept { return mWeatherBackgroundFirstGradientColor; }
QColor ThemeModel::GetWeatherBackgroundSecondGradientColor() const noexcept { return mWeatherBackgroundSecondGradientColor; }
QColor ThemeModel::GetWeatherBackgroundThirdGradientColor() const noexcept { return mWeatherBackgroundThirdGradientColor; }

void ThemeModel::FromJson(const QJsonObject& json)
{
    ThemeModel copy{};

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