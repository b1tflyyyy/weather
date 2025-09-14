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

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/bundled/color.h>

class Logger
{
public:
    using Emp = fmt::emphasis; 
    using Tc = fmt::terminal_color;

    static void Init();
    static std::shared_ptr<spdlog::logger>& GetDefaultLogger();

private:
    static std::shared_ptr<spdlog::logger> mDefaultLogger;
};

#if defined (ENABLE_LOGS)
    #define DEFAULT_LOGGER_INIT() Logger::Init()
    
    #define DEFAULT_LOGGER_ERROR(...)                \
    Logger::GetDefaultLogger()->error(fmt::format(   \
        ::fmt::bg(::fmt::terminal_color::black) |    \
        ::fmt::fg(::fmt::terminal_color::white) |    \
        ::fmt::emphasis(::fmt::emphasis::bold),      \
        __VA_ARGS__                                  \
    ))                                           
    
    #define DEFAULT_LOGGER_WARN(...)                 \
    Logger::GetDefaultLogger()->warn(fmt::format(    \
        ::fmt::bg(::fmt::terminal_color::yellow) |   \
        ::fmt::fg(::fmt::terminal_color::white)  |   \
        ::fmt::emphasis(::fmt::emphasis::bold),      \
        __VA_ARGS__                                  \
    ))
    
    #define DEFAULT_LOGGER_CRITICAL(...)             \
    Logger::GetDefaultLogger()->critical(fmt::format(\
        ::fmt::bg(::fmt::terminal_color::red)   |    \
        ::fmt::fg(::fmt::terminal_color::white) |    \
        ::fmt::emphasis(::fmt::emphasis::bold),      \
        __VA_ARGS__                                  \
    ))
    
    #define DEFAULT_LOGGER_INFO(...)                 \
    Logger::GetDefaultLogger()->info(fmt::format(    \
        ::fmt::bg(::fmt::terminal_color::green) |    \
        ::fmt::fg(::fmt::terminal_color::white) |    \
        ::fmt::emphasis(::fmt::emphasis::bold),      \
        __VA_ARGS__                                  \
    ))

    #define DEFAULT_LOGGER_COLOR_ERROR(background_color, foreground_color, text_style, ...) \
    Logger::GetDefaultLogger()->error(fmt::format(         \
        ::fmt::bg(background_color) |                      \
        ::fmt::fg(foreground_color) |                      \
        ::fmt::emphasis(text_style),                       \
        __VA_ARGS__                                        \
    ))

    #define DEFAULT_LOGGER_COLOR_WARN(background_color, foreground_color, text_style, ...) \
    Logger::GetDefaultLogger()->warn(fmt::format(         \
        ::fmt::bg(background_color) |                     \
        ::fmt::fg(foreground_color) |                     \
        ::fmt::emphasis(text_style),                      \
        __VA_ARGS__                                       \
    ))

    #define DEFAULT_LOGGER_COLOR_CRITICAL(background_color, foreground_color, text_style, ...) \
    Logger::GetDefaultLogger()->critical(fmt::format(         \
        ::fmt::bg(background_color) |                         \
        ::fmt::fg(foreground_color) |                         \
        ::fmt::emphasis(text_style),                          \
        __VA_ARGS__                                           \
    ))

    #define DEFAULT_LOGGER_COLOR_INFO(background_color, foreground_color, text_style, ...) \
    Logger::GetDefaultLogger()->info(fmt::format(         \
        ::fmt::bg(background_color) |                     \
        ::fmt::fg(foreground_color) |                     \
        ::fmt::emphasis(text_style),                      \
        __VA_ARGS__                                       \
    ))
#else 
    #define DEFAULT_LOGGER_INIT()         
    #define DEFAULT_LOGGER_ERROR(...)     
    #define DEFAULT_LOGGER_WARN(...)      
    #define DEFAULT_LOGGER_CRITICAL(...)  
    #define DEFAULT_LOGGER_INFO(...)      
    #define DEFAULT_LOGGER_COLOR_ERROR(...)
    #define DEFAULT_LOGGER_COLOR_WARN(...)
    #define DEFAULT_LOGGER_COLOR_CRITICAL(...)
    #define DEFAULT_LOGGER_COLOR_INFO(...)
#endif