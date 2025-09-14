# MIT License
# 
# Copyright (c) 2025 @Who
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.28)

set(SOURCES main.cpp)
set(QML_SOURCES ${CMAKE_SOURCE_DIR}/ui/qml.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${QML_SOURCES})
enable_qt_autogen(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    qt6_lib
    theme_controller
    theme_list_model
    animation_config_controller
    qml_gradient_background
    user_config_model 
    user_config_controller
    forecast_card_controller
    forecast_card_model
    forecast_card_list_model
    error_handler
    error_emitter
    logger
)