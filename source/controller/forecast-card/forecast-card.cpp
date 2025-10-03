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

#include "forecast-card.hpp"

ForecastCardController::ForecastCardController()
{ 
    SetupConnection();
}

void ForecastCardController::FetchForecast()
{
    // QDateTime date{ QDateTime::fromString("2025-09-20", "yyyy-mm-dd") };
    // DEFAULT_LOGGER_INFO("{}", date.toString("dddd").toStdString());

    mWeatherbitAPIService.FetchMultiDayWeatherForecast();
}

// TODO:
void ForecastCardController::weatherAPIServiceDataFetched(const QByteArray& json)
{
    DEFAULT_LOGGER_INFO("{}\n", QString::fromUtf8(json).toStdString());

    auto dto{ QSharedPointer<WeatherbitDTO>::create() };

    QVector<QSharedPointer<ForecastCardModel>> weather_day_cards_model{};
    weather_day_cards_model.resize(16);

    auto object{ ParseJson(json) };
    dto->FromJson(object);

    for (qsizetype i{}; i < std::size(weather_day_cards_model); ++i)
    {
        auto day{ dto->GetDayData(i) };
        
        DEFAULT_LOGGER_INFO("{}", day->GetDateTime().toString().toStdString());

        weather_day_cards_model[i] = QSharedPointer<ForecastCardModel>::create(
            QStringLiteral("some_image_path"),
            QStringLiteral("description"),
            QString{ "%1, %2" }.arg(dto->GetCountryCode()).arg(dto->GetCityName()),
            day->GetDateTime().toString("dddd"),
            day->GetCurrentTemp(),
            day->GetDayLowTemp(),
            day->GetDayHighTemp()
        );
    }

    emit forecastUpdated(weather_day_cards_model);
    emit forecastFetchedSuccessfully();
}

void ForecastCardController::userConfigUpdated(const UserConfigModel& user_config)
{
    mWeatherbitAPIService.SetUserConfig(user_config);
}

void ForecastCardController::SetupConnection()
{
    QObject::connect(&mWeatherbitAPIService, 
                     &WeatherbitAPIService::weatherForecastFetchedSuccessfully, 
                     this, 
                     &ForecastCardController::weatherAPIServiceDataFetched);
}