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

#include "user-config.hpp"

UserConfigController::UserConfigController(const QString& path)
    : QObject{}
    , mPath{ path }
{ }

void UserConfigController::LoadUserConfig()
{
    DEFAULT_LOGGER_INFO("Loading user config: \"{}\"", mPath.toStdString());

    QFile file{ mPath };
    if (!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error{ std::format("failed to open user config for reading \"{}\"", mPath.toStdString()) };
    }

    QByteArray data{ file.readAll() };
    file.close();

    QJsonParseError err{};
    auto doc{ QJsonDocument::fromJson(data, &err) };

    if (err.error != QJsonParseError::NoError)
    {
        throw std::runtime_error{ std::format("failed to parse json \"{}\"", mPath.toStdString()) };
    }
    if (!doc.isObject())
    {
        throw std::runtime_error{ std::format("json \"{}\" is not an object", mPath.toStdString()) };
    }

    mUserConfigModel = UserConfigModel::FromJSON(doc.object());
}

void UserConfigController::SaveUserConfig()
{
    QFile file{ mPath };
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        throw std::runtime_error{ std::format("failed to open user config for writing \"{}\"", mPath.toStdString()) };
    }

    auto data{ UserConfigModel::ToJSON(mUserConfigModel) };
    file.write(data);

    file.close();
}

QObject* UserConfigController::GetUserConfig() const noexcept { return dynamic_cast<QObject*>(mUserConfigModel.data()); }

