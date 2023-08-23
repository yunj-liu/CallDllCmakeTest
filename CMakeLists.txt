cmake_minimum_required(VERSION 3.5)

project(
  CallMatlabTest
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)

include_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include"
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include\\win64"
  "F:\\MatlabTest\\semicl_vc19\\semicl6\\for_redistribution_files_only")

link_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\lib\\win64\\microsoft"
  "F:\\MatlabTest\\semicl_vc19\\semicl6\\for_redistribution_files_only")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(CallMatlabTest MANUAL_FINALIZATION ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # CallMatlabTest APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(CallMatlabTest SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(CallMatlabTest ${PROJECT_SOURCES})
  endif()
endif()

set(LIB_PROJ
    "libmex.lib"
    "libmx.lib"
    "libmat.lib"
    "libeng.lib"
    "mclmcr.lib"
    "mclmcrrt.lib"
    "semicl6.lib")
target_link_libraries(CallMatlabTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                             ${LIB_PROJ})

set_target_properties(
  CallMatlabTest
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

install(
  TARGETS CallMatlabTest
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(CallMatlabTest)
endif()
