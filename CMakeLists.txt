cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME WineGUI)
set(PROJECT_TARGET winegui)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Get VERSION from most recent git tag
include(git_version)

# Don't forget to update the about_dialog.h VERSION as well
project(${PROJECT_NAME}
  VERSION ${GIT_TAG_VERSION}
  DESCRIPTION "WineGUI is a user-friendly WINE graphical interface"
  LANGUAGES CXX)

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
message("PROJECT_VERSION = ${PROJECT_VERSION}")

# Cmake settings
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CYGWIN)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)

# Use the package PkgConfig to detect (any version) of GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM REQUIRED gtkmm-3.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Production build
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  # Include CPack packaging settings
  include(packaging)
endif()

################################
# Normal Libraries & Executables
################################

# Add GTK libs and local include
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${GTKMM_INCLUDE_DIRS}
)
link_directories(
  ${GTKMM_LIBRARY_DIRS}
)
add_definitions(${GTKMM_CFLAGS_OTHER})

set(HEADERS
    include/menu.h
    include/main_window.h
    include/preferences_window.h
    include/edit_window.h
    include/settings_window.h
    include/busy_dialog.h
    include/bottle_manager.h
    include/bottle_item.h
    include/new_bottle_assistant.h
    include/about_dialog.h
    include/helper.h
    include/signal_dispatcher.h
)

set(SOURCES
    src/menu.cc
    src/main_window.cc
    src/preferences_window.cc
    src/edit_window.cc
    src/settings_window.cc
    src/busy_dialog.cc
    src/bottle_manager.cc
    src/bottle_item.cc
    src/new_bottle_assistant.cc
    src/about_dialog.cc
    src/helper.cc
    src/signal_dispatcher.cc
    ${HEADERS}
)

add_executable(${PROJECT_TARGET} src/main.cc ${SOURCES})

target_link_libraries(${PROJECT_TARGET} Threads::Threads ${CMAKE_THREAD_LIBS_INIT} ${GTKMM_LIBRARIES})

install(TARGETS ${PROJECT_TARGET} RUNTIME DESTINATION "bin" COMPONENT applications)
install(FILES misc/winegui.desktop DESTINATION share/applications)
install(FILES misc/winegui.png DESTINATION share/icons/hicolor/48x48/apps)
install(FILES misc/winegui.svg DESTINATION share/icons/hicolor/scalable/apps)
install(DIRECTORY images DESTINATION share/winegui)
# Could be easily extened with eg. scripts:
#   DIRECTORY images scripts/ DESTINATION ....
#   PATTERN "scripts/*"

# To create 'make run'
add_custom_target( run
  COMMAND "bin/${PROJECT_TARGET}" 
  COMMENT "Starting up..." )

############
# Doxygen  #
############
if(doc)
  include(doxygen)
endif()


