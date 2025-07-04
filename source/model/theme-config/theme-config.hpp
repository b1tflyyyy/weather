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

#include <QColor>
#include <QJsonObject>

#include <QSharedPointer>

class ThemeConfigModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString themeName READ GetThemeName CONSTANT);
    
    Q_PROPERTY(QColor dailyForecastDayColor READ GetDailyForecastDayColor CONSTANT);
    Q_PROPERTY(QColor dailyForecastDegreesColor READ GetDailyForecastDegreesColor CONSTANT);
    Q_PROPERTY(QColor dailyForecastHighLowDegreesColor READ GetDailyForecastHighLowDegreesColor CONSTANT);
    Q_PROPERTY(QColor dailyForecastLocationColor READ GetDailyForecastLocationColor CONSTANT);
    Q_PROPERTY(QColor dailyForecastDescriptionColor READ GetDailyForecastDescriptionColor CONSTANT);
    Q_PROPERTY(QColor dailyForecastCardColor READ GetDailyForecastCardColor CONSTANT);

    Q_PROPERTY(QColor hourlyForecastDegreesColor READ GetHourlyForecastDegreesColor CONSTANT);
    Q_PROPERTY(QColor hourlyForecastTimeColor READ GetHourlyForecastTimeColor CONSTANT);
    Q_PROPERTY(QColor hourlyForecastCardColor READ GetHourlyForecastCardColor CONSTANT);

    Q_PROPERTY(QColor weatherBackgroundFirstColor READ GetWeatherBackgroundFirstColor CONSTANT);
    Q_PROPERTY(QColor weatherBackgroundSecondColor READ GetWeatherBackgroundSecondColor CONSTANT);
    Q_PROPERTY(QColor weatherBackgroundThirdColor READ GetWeatherBackgroundThirdColor CONSTANT);

    Q_PROPERTY(qreal weatherBackgroundFirstColorPosition READ GetWeatherBackgroundFirstColorPosition CONSTANT);
    Q_PROPERTY(qreal weatherBackgroundSecondColorPosition READ GetWeatherBackgroundSecondColorPosition CONSTANT);
    Q_PROPERTY(qreal weatherBackgroundThirdColorPosition READ GetWeatherBackgroundThirdColorPosition CONSTANT);

public: 
    ThemeConfigModel() = default;
    ~ThemeConfigModel() noexcept override = default;

    ThemeConfigModel(const ThemeConfigModel&) = delete;
    ThemeConfigModel& operator=(const ThemeConfigModel&) = delete;

    ThemeConfigModel(ThemeConfigModel&&) = delete;
    ThemeConfigModel& operator=(ThemeConfigModel&&) = delete;

    QString GetThemeName() const noexcept;

    QColor GetDailyForecastDayColor() const noexcept;
    QColor GetDailyForecastDegreesColor() const noexcept;
    QColor GetDailyForecastHighLowDegreesColor() const noexcept;
    QColor GetDailyForecastLocationColor() const noexcept;
    QColor GetDailyForecastDescriptionColor() const noexcept;
    QColor GetDailyForecastCardColor() const noexcept;

    QColor GetHourlyForecastDegreesColor() const noexcept;
    QColor GetHourlyForecastTimeColor() const noexcept;
    QColor GetHourlyForecastCardColor() const noexcept;

    QColor GetWeatherBackgroundFirstColor() const noexcept;
    QColor GetWeatherBackgroundSecondColor() const noexcept;
    QColor GetWeatherBackgroundThirdColor() const noexcept;

    qreal GetWeatherBackgroundFirstColorPosition() const noexcept;
    qreal GetWeatherBackgroundSecondColorPosition() const noexcept;
    qreal GetWeatherBackgroundThirdColorPosition() const noexcept;

    static QSharedPointer<ThemeConfigModel> FromJSON(const QJsonObject& obj);

private:
    // Theme Name
    QString mThemeName;

    // Daily Forecast Card
    QColor mDailyForecastDayColor;
    QColor mDailyForecastDegreesColor;
    QColor mDailyForecastHighLowDegreesColor;
    QColor mDailyForecastLocationColor;
    QColor mDailyForecastDescriptionColor;
    QColor mDailyForecastCardColor;

    // Hourly Forecast Card
    QColor mHourlyForecastDegreesColor;
    QColor mHourlyForecastTimeColor;
    QColor mHourlyForecastCardColor;

    // Weather Background Gradient
    QColor mWeatherBackgroundFirstColor;
    QColor mWeatherBackgroundSecondColor;
    QColor mWeatherBackgroundThirdColor;

    qreal mWeatherBackgroundFirstColorPosition;
    qreal mWeatherBackgroundSecondColorPosition;
    qreal mWeatherBackgroundThirdColorPosition;
};