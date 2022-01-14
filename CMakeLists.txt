cmake_minimum_required(VERSION 3.5)

project(SNAKE LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC on)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb ")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(SNAKE_SRC 
    main.cpp
    graph_view.cpp
    game_mode_view.cpp
    game_mode_info_view.cpp
    game_over_view.cpp
    game_unit.cpp
    snake_unit.cpp
    game_view.cpp
    game.cpp
    layout_item.cpp
    textedit_item.cpp
    )

set(SNAKE_HEAD 
    log.h
    common_view.h
    graph_view.h
    game_mode_view.h
    game_mode_info_view.h
    game_over_view.h
    game_unit.h
    snake_unit.h
    game_view.h
    game.h
    layout_item.h
    textedit_item.h
    )

add_executable( SNAKE
    ${SNAKE_SRC}
    ${SNAKE_HEAD}
)


target_link_libraries(SNAKE PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

