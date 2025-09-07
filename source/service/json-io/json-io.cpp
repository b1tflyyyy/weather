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

#include "json-io.hpp"

void JsonIO::ReadJson(IFromJson* abstract_object, const QString& path, QFlags<QIODeviceBase::OpenModeFlag> flags)
{
    QFile file{ path };
    if (!file.open(flags))
    {
        throw std::runtime_error{ std::format("failed to open \"{}\"", path.toStdString()) };
    }

    QByteArray data{ file.readAll() };
    file.close();

    QJsonParseError err{};
    auto document{ QJsonDocument::fromJson(data) };

    if (err.error != QJsonParseError::NoError)
    {
        throw std::runtime_error{ std::format("failed to parse json \"{}\"", path.toStdString()) };
    }
    if (!document.isObject())
    {
        throw std::runtime_error{ std::format("json \"{}\" is not an object", path.toStdString()) };
    }

    abstract_object->FromJson(document.object());
}

void JsonIO::WriteJson(const IToJson* abstract_object, const QString& path, QFlags<QIODeviceBase::OpenModeFlag> flags)
{
    QFile file{ path };
    if (!file.open(flags))
    {
        throw std::runtime_error{ std::format("failed to open \"{}\"", path.toStdString()) };
    }

    file.write(QJsonDocument{ abstract_object->ToJson() }.toJson());
    file.close();
}

QJsonArray JsonIO::ReadJsonArray(const QString& path, QFlags<QIODeviceBase::OpenModeFlag> flags)    
{
    QFile file{ path };
    if (!file.open(flags))
    {
        throw std::runtime_error{ std::format("failed to open \"{}\"", path.toStdString()) };
    }

    QByteArray data{ file.readAll() };
    file.close();

    QJsonParseError err{};
    auto document{ QJsonDocument::fromJson(data) };

    if (err.error != QJsonParseError::NoError)
    {
        throw std::runtime_error{ std::format("failed to parse json \"{}\"", path.toStdString()) };
    }
    if (!document.isArray())
    {
        throw std::runtime_error{ std::format("json \"{}\" is not an array", path.toStdString()) };
    }

    return document.array();
}   

void JsonIO::WriteJsonArray(const QVector<IToJson*>& container, const QString& path, QFlags<QIODeviceBase::OpenModeFlag> flags)
{
    QFile file{ path };
    if (!file.open(flags))
    {
        throw std::runtime_error{ std::format("failed to open \"{}\"", path.toStdString()) };
    }

    QJsonArray array{};
    for (const auto* el : container)
    {
        array.push_back(el->ToJson());
    }

    file.write(QJsonDocument{ array }.toJson());
    file.close();
}