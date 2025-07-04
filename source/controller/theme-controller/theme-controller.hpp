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
#include <QVector>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include <model/theme-model/theme-model.hpp>

class ThemeController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* currentTheme READ GetCurrentTheme NOTIFY currentThemeChanged)

public:
    explicit ThemeController(QObject* parent = nullptr);
    ~ThemeController() noexcept override = default;

    ThemeController(const ThemeController&) = delete;
    ThemeController& operator=(const ThemeController&) = delete;

    ThemeController(ThemeController&&) noexcept = delete;
    ThemeController& operator=(ThemeController&&) noexcept = delete;

    void LoadThemes(const QString& path);
    
    QObject* GetCurrentTheme();
    Q_INVOKABLE void SetCurrentTheme(qsizetype index);

    const QVector<QSharedPointer<ThemeModel>>& GetThemes() const noexcept;

signals:
    void currentThemeChanged();

private:
    QVector<QSharedPointer<ThemeModel>> mThemes;
    qsizetype mCurrentThemeIndex;
};