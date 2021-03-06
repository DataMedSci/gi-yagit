# This file is part of 'yet Another Gamma Index Tool'.
#
# 'yet Another Gamma Index Tool' is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# 'yet Another Gamma Index Tool' is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with 'yet Another Gamma Index Tool'; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

cmake_minimum_required(VERSION 3.8)
project(yAGITQt)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(common)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

find_c_and_cpp_files("${CMAKE_CURRENT_SOURCE_DIR}/include" yAGITQt_includes)
find_c_and_cpp_files("${CMAKE_CURRENT_SOURCE_DIR}/src" yAGITQt_sources)
find_ui_files("${CMAKE_CURRENT_SOURCE_DIR}/ui" yAGITQt_uis)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${yAGITQt_includes} ${yAGITQt_sources})

add_executable(yAGITQt ${yAGITQt_includes} ${yAGITQt_sources} ${yAGITQt_uis})

target_link_libraries(yAGITQt PRIVATE gi_core gi_additions gi_wrapper Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(yAGITQt PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(yAGITQt
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set_default_output_directories(yAGITQt)
