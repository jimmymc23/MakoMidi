cmake_minimum_required(VERSION 3.16)

project(MakoR1-MidiControl VERSION 0.1 LANGUAGES CXX)

# Enable automatic handling of MOC, UIC, and RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt package
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Include RtMidi
find_package(PkgConfig REQUIRED)
pkg_check_modules(RTMIDI REQUIRED rtmidi)
include_directories(${RTMIDI_INCLUDE_DIRS})

# Define source files for the project
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Create the executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MakoR1-MidiControl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MakoR1-MidiControl SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MakoR1-MidiControl
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link against Qt and RtMidi libraries
target_link_libraries(MakoR1-MidiControl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${RTMIDI_LIBRARIES} asound)

# Set target properties for macOS and iOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MakoR1-MidiControl)
endif()
set_target_properties(MakoR1-MidiControl PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation settings
include(GNUInstallDirs)
install(TARGETS MakoR1-MidiControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MakoR1-MidiControl)
endif()

