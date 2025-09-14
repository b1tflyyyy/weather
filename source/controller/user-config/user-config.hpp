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
#include <QFile>

#include <model/user-config/user-config.hpp>

#include <utils/logger/logger.hpp>
#include <utils/error-handling/error-emitter/error-emitter.hpp>

#include <service/json-io/json-io.hpp>

#include <interface/iconfig.hpp>
#include <interface/ipath.hpp>
#include <interface/ierror-emitter.hpp>

class UserConfigController 
    : public QObject
    , public IConfigStorage
    , public IPath
    , public IErrorEmitter
    , protected JsonIO
{
    Q_OBJECT

    Q_PROPERTY(QObject* userConfig READ GetUserConfig CONSTANT);

public:
    void SetPath(const QString& path) override;
    const QString& GetPath() const noexcept override;

    Q_INVOKABLE void Load() override;
    Q_INVOKABLE void Save() override;

    ErrorEmitter* GetErrorEmitter() override;

    QObject* GetUserConfig();
    const UserConfigModel& GetInternalUserConfig() const noexcept; 
    
signals:
    void userConfigLoadedSuccessfully(const UserConfigModel& user_config);

private:
    QString mPath;
    UserConfigModel mUserConfigModel;
    ErrorEmitter mErrorEmitter;
};