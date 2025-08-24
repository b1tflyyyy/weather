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

ForecastCardModel::ForecastCardModel(const QString& weather_image,
                                     const QString& weather_description,
                                     const QString& location,
                                     const QString& day,
                                     std::int64_t degrees,
                                     std::int64_t degrees_low,
                                     std::int64_t degrees_high)
                        : mWeatherImage{ weather_image }
                        , mWeatherDescription{ weather_description }
                        , mLocation{ location }
                        , mDay{ day }
                        , mDegrees{ degrees }
                        , mDegreesLow{ degrees_low }
                        , mDegreesHigh{ degrees_high }
{ }

bool ForecastCardModel::operator==(const ForecastCardModel& rhs) const noexcept
{
    return mLocation    == rhs.mLocation    &&
           mDay         == rhs.mDay         &&
           mDegrees     == rhs.mDegrees     &&
           mDegreesLow  == rhs.mDegreesLow  &&
           mDegreesHigh == rhs.mDegreesHigh;
}

bool ForecastCardModel::operator!=(const ForecastCardModel& rhs) const noexcept
{
    return !(*this == rhs);
}

void ForecastCardModel::SetWeatherImage(const QString& weather_image)
{
    if (mWeatherImage != weather_image)
    {
        mWeatherImage = weather_image;
        emit weatherImageChanged();
    }
}

QString ForecastCardModel::GetWeatherImage() const noexcept { return mWeatherImage; }

void ForecastCardModel::SetWeatherDescription(const QString& weather_description)
{
    if (mWeatherDescription != weather_description)
    {
        mWeatherDescription = weather_description;
        emit weatherDescriptionChanged();
    }
}

QString ForecastCardModel::GetWeatherDescription() const noexcept { return mWeatherDescription; }

void ForecastCardModel::SetLocation(const QString& location)
{
    if (mLocation != location)
    {
        mLocation = location;
        emit locationChanged();
    }
}

QString ForecastCardModel::GetLocation() const noexcept { return mLocation; }

void ForecastCardModel::SetDay(const QString& day)
{
    if (mDay != day)
    {
        mDay = day;
        emit dayChanged();
    }
}

QString ForecastCardModel::GetDay() const noexcept { return mDay; }

void ForecastCardModel::SetDegrees(std::int64_t degrees)
{
    if (mDegrees != degrees)
    {
        mDegrees = degrees;
        emit degreesChanged();
    }
}
    
std::int64_t ForecastCardModel::GetDegrees() const noexcept { return mDegrees; }

void ForecastCardModel::SetDegreesLow(std::int64_t degrees_low)
{
    if (mDegreesLow != degrees_low)
    {
        mDegreesLow = degrees_low;
        emit degreesLowChanged();
    }
}

std::int64_t ForecastCardModel::GetDegreesLow() const noexcept { return mDegreesLow; }

void ForecastCardModel::SetDegreesHigh(std::int64_t degrees_high)
{
    if (mDegreesHigh != degrees_high)
    {
        mDegreesHigh = degrees_high;
        emit degreesHighChanged();
    }
}

std::int64_t ForecastCardModel::GetDegreesHigh() const noexcept { return mDegreesHigh; }