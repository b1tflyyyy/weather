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

void UserConfigController::SetPath(const QString& path) { mPath = path; }
const QString& UserConfigController::GetPath() const noexcept { return mPath; }

void UserConfigController::Load()
{
    try 
    {
        ReadJson(&mUserConfigModel, mPath);
        emit userConfigLoadedSuccessfully(mUserConfigModel);
    }
    catch (const std::runtime_error& e)
    {
        mErrorEmitter.ReportError(e.what(), ErrorEmitter::ErrorStatus::CRITICAL);
        return;
    }
    catch (...)
    {
        mErrorEmitter.ReportError(QStringLiteral("unexpected error at {} path {}").arg(__PRETTY_FUNCTION__).arg(mPath), ErrorEmitter::ErrorStatus::CRITICAL);
        return;
    }
}

void UserConfigController::Save()
{
    try 
    {
        WriteJson(&mUserConfigModel, mPath, QIODeviceBase::WriteOnly | QIODeviceBase::Truncate);
    }
    catch (const std::runtime_error& e)
    {
        mErrorEmitter.ReportError(e.what(), ErrorEmitter::ErrorStatus::CRITICAL);
        return;
    }
    catch (...)
    {
        mErrorEmitter.ReportError(QStringLiteral("unexpected error at {} path {}").arg(__PRETTY_FUNCTION__).arg(mPath), ErrorEmitter::ErrorStatus::CRITICAL);
        return;
    }
}

ErrorEmitter* UserConfigController::GetErrorEmitter() { return &mErrorEmitter; }

QObject* UserConfigController::GetUserConfig() { return dynamic_cast<QObject*>(&mUserConfigModel); }
const UserConfigModel& UserConfigController::GetInternalUserConfig() const noexcept { return mUserConfigModel; }

