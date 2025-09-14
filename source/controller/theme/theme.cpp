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

#include "theme.hpp"

void ThemeController::SetPath(const QString& path)
{
    mPath = path;
}

const QString& ThemeController::GetPath() const noexcept
{
    return mPath;
}

void ThemeController::Load()
{
    try 
    {
        auto array{ ReadJsonArray(mPath) };
    
        QVector<QSharedPointer<ThemeModel>> theme_list;
        theme_list.resize(std::size(array));

        for (std::size_t i{}; i < std::size(array); ++i)
        {
            theme_list[i] = QSharedPointer<ThemeModel>::create();
            theme_list[i]->FromJson(array[i].toObject());
        }

        emit themeListLoadedSuccessfully(theme_list);
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

ErrorEmitter* ThemeController::GetErrorEmitter()
{
    return &mErrorEmitter;
}

