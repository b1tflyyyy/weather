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

#include "weatherbit-api.hpp"

void WeatherbitAPIService::FetchMultiDayWeatherForecast()
{
    QNetworkReply* reply{ mNetworkAccessManager.get(mDailyRequest) };
    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply]() -> void
    {
        if (reply->error() != QNetworkReply::NoError)
        {
            DEFAULT_LOGGER_ERROR("Error: request {}\n", reply->url().toString().toStdString());
            return;
        }

        QByteArray bytes{ reply->readAll() };
        emit weatherForecastFetchedSuccessfully(bytes);
    });
}

void WeatherbitAPIService::SetUserConfig(const UserConfigModel& user_config)
{
    InitRequests(user_config.GetLongitude(), 
                 user_config.GetLatitude(),
                 user_config.GetUnits(),
                 user_config.GetWeatherAPIToken());
}

void WeatherbitAPIService::InitRequests(double longitude, double latitude, const QString& units, const QString& token)
{
    {
        QUrl url{ QStringLiteral("https://weatherbit-v1-mashape.p.rapidapi.com/forecast/daily") };
        QUrlQuery query;

        query.addQueryItem(QStringLiteral("lat"), QString::number(latitude));
        query.addQueryItem(QStringLiteral("lon"), QString::number(longitude));
        query.addQueryItem(QStringLiteral("units"), units);

        url.setQuery(query);

        mDailyRequest.setUrl(url);

        mDailyRequest.setRawHeader(QByteArray{ "x-rapidapi-host" }, QByteArray{ "weatherbit-v1-mashape.p.rapidapi.com" });
        mDailyRequest.setRawHeader(QByteArray{ "X-RapidAPI-Key" }, token.toUtf8());
    }
}