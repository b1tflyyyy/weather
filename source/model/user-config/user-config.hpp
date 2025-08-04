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
#include <QSharedPointer>

#include <QJsonDocument>
#include <QJsonObject>

class UserConfigModel : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(QString city READ GetCity CONSTANT);
    Q_PROPERTY(std::size_t themeIndex READ GetThemeIndex WRITE SetThemeIndex CONSTANT);

public:
    UserConfigModel() = default;
    ~UserConfigModel() noexcept override = default;

    const QString& GetCity() const noexcept;
    
    std::size_t GetThemeIndex() const noexcept;
    void SetThemeIndex(std::size_t idx);

    static QSharedPointer<UserConfigModel> FromJSON(const QJsonObject& obj);
    static QByteArray ToJSON(const QSharedPointer<UserConfigModel>& cfg);

private:
    QString mCity;
    std::size_t mThemeIndex;
};