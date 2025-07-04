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

#include "theme-config-list.hpp"

ThemeConfigListModel::ThemeConfigListModel(const QVector<QSharedPointer<ThemeConfigModel>>& themes, QObject* parent)
    : QAbstractListModel{ parent }
    , mThemes{ themes }
{ }

int ThemeConfigListModel::rowCount([[maybe_unused]] const QModelIndex& index) const { return mThemes.size(); }

QVariant ThemeConfigListModel::data(const QModelIndex& index, int role) const
{
    const auto& el{ mThemes[index.row()] };
    switch (role) 
    {
        case ThemeConfigListModel::Roles::ThemeName: return el->GetThemeName(); 
        case ThemeConfigListModel::Roles::WeatherBackgroundFirstColor: return el->GetWeatherBackgroundFirstColor();
        case ThemeConfigListModel::Roles::WeatherBackgroundSecondColor: return el->GetWeatherBackgroundSecondColor();
        case ThemeConfigListModel::Roles::WeatherBackgroundThirdColor: return el->GetWeatherBackgroundThirdColor();
        case ThemeConfigListModel::Roles::WeatherBackgroundFirstColorPosition: return el->GetWeatherBackgroundFirstColorPosition();
        case ThemeConfigListModel::Roles::WeatherBackgroundSecondColorPosition: return el->GetWeatherBackgroundSecondColorPosition();
        case ThemeConfigListModel::Roles::WeatherBackgroundThirdColorPosition: return el->GetWeatherBackgroundThirdColorPosition();
        default: return {};
    }
}

QHash<int, QByteArray> ThemeConfigListModel::roleNames() const 
{
    return 
    {
        { ThemeConfigListModel::Roles::ThemeName, "themeName" },
        { ThemeConfigListModel::Roles::WeatherBackgroundFirstColor, "weatherBackgroundFirstColor" },
        { ThemeConfigListModel::Roles::WeatherBackgroundSecondColor, "weatherBackgroundSecondColor" },
        { ThemeConfigListModel::Roles::WeatherBackgroundThirdColor, "weatherBackgroundThirdColor" },
        { ThemeConfigListModel::Roles::WeatherBackgroundFirstColorPosition, "weatherBackgroundFirstColorPosition" },
        { ThemeConfigListModel::Roles::WeatherBackgroundSecondColorPosition, "weatherBackgroundSecondColorPosition" },
        { ThemeConfigListModel::Roles::WeatherBackgroundThirdColorPosition, "weatherBackgroundThirdColorPosition" }
    };
}