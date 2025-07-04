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

QColor ThemeConfigModel::GetWeatherBackgroundFirstColor() const noexcept { return mWeatherBackgroundFirstColor; }
QColor ThemeConfigModel::GetWeatherBackgroundSecondColor() const noexcept { return mWeatherBackgroundSecondColor; }
QColor ThemeConfigModel::GetWeatherBackgroundThirdColor() const noexcept { return mWeatherBackgroundThirdColor; }

qreal ThemeConfigModel::GetWeatherBackgroundFirstColorPosition() const noexcept { return mWeatherBackgroundFirstColorPosition; }
qreal ThemeConfigModel::GetWeatherBackgroundSecondColorPosition() const noexcept { return mWeatherBackgroundSecondColorPosition; }
qreal ThemeConfigModel::GetWeatherBackgroundThirdColorPosition() const noexcept { return mWeatherBackgroundThirdColorPosition; }

QSharedPointer<ThemeConfigModel> ThemeConfigModel::FromJSON(const QJsonObject& obj) 
{
    auto model{ QSharedPointer<ThemeConfigModel>::create() };
    model->mThemeName = obj.value(QStringLiteral("ThemeName")).toString();

    model->mDailyForecastDayColor = obj.value(QStringLiteral("DailyForecastDayColor")).toString();
    model->mDailyForecastDegreesColor = obj.value(QStringLiteral("DailyForecastDegreesColor")).toString();
    model->mDailyForecastHighLowDegreesColor = obj.value(QStringLiteral("DailyForecastHighLowDegreesColor")).toString();
    model->mDailyForecastLocationColor = obj.value(QStringLiteral("DailyForecastLocationColor")).toString();
    model->mDailyForecastDescriptionColor = obj.value(QStringLiteral("DailyForecastDescriptionColor")).toString();
    model->mDailyForecastCardColor = obj.value(QStringLiteral("DailyForecastCardColor")).toString();

    model->mHourlyForecastDegreesColor = obj.value(QStringLiteral("HourlyForecastDegreesColor")).toString();
    model->mHourlyForecastTimeColor = obj.value(QStringLiteral("HourlyForecastTimeColor")).toString();
    model->mHourlyForecastCardColor = obj.value(QStringLiteral("HourlyForecastCardColor")).toString();

    model->mWeatherBackgroundFirstColor = obj.value(QStringLiteral("WeatherBackgroundFirstColor")).toString();
    model->mWeatherBackgroundSecondColor = obj.value(QStringLiteral("WeatherBackgroundSecondColor")).toString();
    model->mWeatherBackgroundThirdColor = obj.value(QStringLiteral("WeatherBackgroundThirdColor")).toString();

    model->mWeatherBackgroundFirstColorPosition = obj.value(QStringLiteral("WeatherBackgroundFirstColorPosition")).toDouble();
    model->mWeatherBackgroundSecondColorPosition = obj.value(QStringLiteral("WeatherBackgroundSecondColorPosition")).toDouble();
    model->mWeatherBackgroundThirdColorPosition = obj.value(QStringLiteral("WeatherBackgroundThirdColorPosition")).toDouble();

    return model;
}