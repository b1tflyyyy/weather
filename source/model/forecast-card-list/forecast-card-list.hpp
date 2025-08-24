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
#include <QVector>
#include <QSharedPointer>
#include <QAbstractListModel>

#include <cassert>
#include <algorithm>

#include <model/forecast-card/forecast-card.hpp>

class ForecastCardListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        WeatherImage = Qt::UserRole + 1,
        WeatherDescription,
        Location,
        Day,
        Degrees,
        DegreesLow,
        DegreesHigh
    };

    ForecastCardListModel();

    int rowCount([[maybe_unused]] const QModelIndex& index) const override;
    QVariant data(const QModelIndex& index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:
    void setForecastCards(const QVector<QSharedPointer<ForecastCardModel>>& forecast_cards);

private:
    QVector<QSharedPointer<ForecastCardModel>> mForecastCards;
};