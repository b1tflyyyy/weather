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

class ForecastCardModel : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(QString weatherImage READ GetWeatherImage WRITE SetWeatherImage NOTIFY weatherImageChanged);
    Q_PROPERTY(QString weatherDescription READ GetWeatherDescription WRITE SetWeatherDescription NOTIFY weatherDescriptionChanged);
    Q_PROPERTY(QString location READ GetLocation WRITE SetLocation NOTIFY locationChanged);
    Q_PROPERTY(QString day READ GetDay WRITE SetDay NOTIFY dayChanged);

    Q_PROPERTY(std::int64_t degrees READ GetDegrees WRITE SetDegrees NOTIFY degreesChanged);
    Q_PROPERTY(std::int64_t degreesLow READ GetDegreesLow WRITE SetDegreesLow NOTIFY degreesLowChanged);
    Q_PROPERTY(std::int64_t degreesHigh READ GetDegreesHigh WRITE SetDegreesHigh NOTIFY degreesHighChanged);

public:
    ForecastCardModel() = default;
    ForecastCardModel(const QString& weather_image,
                      const QString& weather_description,
                      const QString& location,
                      const QString& day,
                      std::int64_t degrees,
                      std::int64_t degrees_low,
                      std::int64_t degrees_high);

    ForecastCardModel(const ForecastCardModel&) = delete;
    ForecastCardModel& operator=(const ForecastCardModel&) = delete;

    ForecastCardModel(ForecastCardModel&&) = delete;
    ForecastCardModel& operator=(ForecastCardModel&&) = delete;

    ~ForecastCardModel() noexcept override = default;

    bool operator==(const ForecastCardModel& rhs) const noexcept;
    bool operator!=(const ForecastCardModel& rhs) const noexcept;

    void SetWeatherImage(const QString& weather_image);
    QString GetWeatherImage() const noexcept;

    void SetWeatherDescription(const QString& weather_description);
    QString GetWeatherDescription()  const noexcept;

    void SetLocation(const QString& location);
    QString GetLocation() const noexcept;

    void SetDay(const QString& day);
    QString GetDay() const noexcept;

    void SetDegrees(std::int64_t degrees);
    std::int64_t GetDegrees() const noexcept;

    void SetDegreesLow(std::int64_t degrees_low);
    std::int64_t GetDegreesLow() const noexcept;

    void SetDegreesHigh(std::int64_t degrees_high);
    std::int64_t GetDegreesHigh() const noexcept;

signals:
    void weatherImageChanged();
    void weatherDescriptionChanged();
    void locationChanged();
    void dayChanged();
    void degreesChanged();
    void degreesLowChanged();
    void degreesHighChanged();

private:
    QString mWeatherImage;
    QString mWeatherDescription;

    QString mLocation;
    QString mDay;

    std::int64_t mDegrees;

    std::int64_t mDegreesLow;
    std::int64_t mDegreesHigh;
};