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

#include "theme-list.hpp"

int ThemeListModel::rowCount([[maybe_unused]] const QModelIndex& index) const { return mThemes.size(); }

QVariant ThemeListModel::data(const QModelIndex& index, int role) const
{
    const auto& el{ mThemes[index.row()] };
    switch (role) 
    {
        case ThemeListModel::Roles::ThemeName: return el->GetThemeName(); 
        case ThemeListModel::Roles::WeatherBackgroundFirstColor: return el->GetWeatherBackgroundFirstGradientColor();
        case ThemeListModel::Roles::WeatherBackgroundSecondColor: return el->GetWeatherBackgroundSecondGradientColor();
        case ThemeListModel::Roles::WeatherBackgroundThirdColor: return el->GetWeatherBackgroundThirdGradientColor();
        case ThemeListModel::Roles::WeatherBackgroundFirstColorPosition: return 0.3f;  // gradient position in qml, maybe refactor this
        case ThemeListModel::Roles::WeatherBackgroundSecondColorPosition: return 0.6f; // gradient position in qml, maybe refactor this
        case ThemeListModel::Roles::WeatherBackgroundThirdColorPosition: return 0.9f;  // gradient position in qml, maybe refactor this
        default: return {};
    }
}

QHash<int, QByteArray> ThemeListModel::roleNames() const 
{
    return 
    {
        { ThemeListModel::Roles::ThemeName, "themeName" },
        { ThemeListModel::Roles::WeatherBackgroundFirstColor, "weatherBackgroundFirstColor" },
        { ThemeListModel::Roles::WeatherBackgroundSecondColor, "weatherBackgroundSecondColor" },
        { ThemeListModel::Roles::WeatherBackgroundThirdColor, "weatherBackgroundThirdColor" },
        { ThemeListModel::Roles::WeatherBackgroundFirstColorPosition, "weatherBackgroundFirstColorPosition" },
        { ThemeListModel::Roles::WeatherBackgroundSecondColorPosition, "weatherBackgroundSecondColorPosition" },
        { ThemeListModel::Roles::WeatherBackgroundThirdColorPosition, "weatherBackgroundThirdColorPosition" }
    };
}

void ThemeListModel::ChangeCurrentTheme(std::size_t index)
{
    if (index != mCurrentThemeIndex)
    {
        mCurrentThemeIndex = index;
        emit currentThemeChanged();
    }
}

QObject* ThemeListModel::GetCurrentTheme() const noexcept
{
    return dynamic_cast<QObject*>(std::data(mThemes[mCurrentThemeIndex]));
}

void ThemeListModel::themeListUpdate(const QVector<QSharedPointer<ThemeModel>>& theme_list)
{
    beginResetModel();
    mThemes = theme_list;
    endResetModel();
}

void ThemeListModel::userConfigLoaded(const UserConfigModel& user_config)
{
    ChangeCurrentTheme(user_config.GetThemeIndex());
}