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

#include "forecast-card-list.hpp"

ForecastCardListModel::ForecastCardListModel()
{
    auto init{ QSharedPointer<ForecastCardModel>::create(
        QStringLiteral("qrc:/assets/images/windy.png"),
        QStringLiteral("undef"),
        QStringLiteral("undef"),
        QStringLiteral("undef"),
        -1,
        -1,
        -1
    ) };

    std::fill_n(std::back_inserter(mForecastCards), 16, init); // 7 - week days 
}

int ForecastCardListModel::rowCount([[maybe_unused]] const QModelIndex& index) const { return std::size(mForecastCards); }

QVariant ForecastCardListModel::data(const QModelIndex& index, int role) const
{
    const auto& el{ mForecastCards[index.row()] };
    switch (role) 
    {
    case ForecastCardListModel::Roles::WeatherImage: return el->GetWeatherImage();
    case ForecastCardListModel::Roles::WeatherDescription: return el->GetWeatherDescription();
    case ForecastCardListModel::Roles::Location: return el->GetLocation();
    case ForecastCardListModel::Roles::Day: return el->GetDay();
    case ForecastCardListModel::Roles::Degrees: return QVariant::fromValue(el->GetDegrees());
    case ForecastCardListModel::Roles::DegreesLow: return QVariant::fromValue(el->GetDegreesLow());
    case ForecastCardListModel::Roles::DegreesHigh: return QVariant::fromValue(el->GetDegreesHigh());
    default: return {};
    }
}

QHash<int, QByteArray> ForecastCardListModel::roleNames() const
{
    return 
    {
        { ForecastCardListModel::Roles::WeatherImage, "weatherImage" },
        { ForecastCardListModel::Roles::WeatherDescription, "weatherDescription" },
        { ForecastCardListModel::Roles::Location, "location" },
        { ForecastCardListModel::Roles::Day, "day" },
        { ForecastCardListModel::Roles::Degrees, "degrees" },
        { ForecastCardListModel::Roles::DegreesLow, "degreesLow" },
        { ForecastCardListModel::Roles::DegreesHigh, "degreesHigh" }
    };
}

void ForecastCardListModel::setForecastCards(const QVector<QSharedPointer<ForecastCardModel>>& forecast_cards)
{
    assert(std::size(mForecastCards) >= std::size(forecast_cards));

    for (std::ptrdiff_t i{}; i < std::size(forecast_cards); ++i)
    {
        if (mForecastCards[i] != forecast_cards[i])
        {
            mForecastCards[i] = forecast_cards[i];
            emit dataChanged(index(i), index(i));
        }
    }
}