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
#include <QSharedPointer>
#include <QVector>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include <QUrl>
#include <QUrlQuery>

#include <thread>

#include <model/forecast-card/forecast-card.hpp>
#include <model/user-config/user-config.hpp>

#include <utils/logger/logger.hpp>

#include <service/weatherbit-api/weatherbit-api.hpp>

class ForecastCardController : public QObject
{
    Q_OBJECT

public:
    ForecastCardController(const UserConfigModel& user_config_model);

    Q_INVOKABLE void FetchForecast();

signals:
    void forecastFetchedSuccessfully();
    void forecastUpdated(const QVector<QSharedPointer<ForecastCardModel>>& forecast_cards);
    
public slots:
    void weatherAPIServiceDataFetched(const QString& json);

private:
    void SetupConnection();

private:
    WeatherbitAPIService mWeatherbitAPIService;
};