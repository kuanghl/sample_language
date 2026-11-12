# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8...3.5)

project(samples_cpp LANGUAGES C CXX)

if(MSVC)
  # /std:c++14
  # /std:c++17
  # /std:c++20
  # /std:c++latest
  # /std:c11
  # /std:c17
  # /std:clatest
  set(CMAKE_C_FLAGS "/std:c11 /experimental:c11atomics")
  set(CMAKE_CXX_FLAGS "/std:c++11")
endif()

# build binary place ./bin
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # todo...
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # c++ version
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED True)
else()
	message(STATUS "Error Config Environment Failed: ${CMAKE_SYSTEM_NAME}")
endif()

# place binaries and libraries according to GNU standards
# ${CMAKE_INSTALL_SBINDIR}        /sbin
# ${CMAKE_INSTALL_LIBDIR}         /lib or /lib64
# ${CMAKE_INSTALL_BINDIR}         /bin
# ${CMAKE_INSTALL_INCLUDEDIR}     /include
# ${CMAKE_INSTALL_DATAROOTDIR}    /share
# ${CMAKE_INSTALL_LOCALSTATEDIR}  /var
# ${CMAKE_INSTALL_RUNSTATEDIR}    /var/run
# ${CMAKE_INSTALL_DATADIR}        /share
# ${CMAKE_INSTALL_INFODIR}        /share/info
# ${CMAKE_INSTALL_LOCALEDIR}      /share/locale
# ${CMAKE_INSTALL_MANDIR}         /share/man
# ${CMAKE_INSTALL_DOCDIR}         /share/doc/${PROJECT_NAME}
include(GNUInstallDirs) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# build message info
message(STATUS "list build info:

    Target system       : ${CMAKE_SYSTEM_NAME}
    Target type         : ${CMAKE_BUILD_TYPE}
    Host:
      CMake version     : ${CMAKE_VERSION}
      Generator         : ${CMAKE_GENERATOR}
      Processor         : ${CMAKE_SYSTEM_PROCESSOR}
      Source directory  : ${CMAKE_SOURCE_DIR}
    Compiler:
      C standard        : ${CMAKE_C_STANDARD}
      C compiler        : ${CMAKE_C_COMPILER} ${CMAKE_C_COMPILER_VERSION}
      C FLAGS           : ${CMAKE_C_FLAGS}
      C DEBUG FLAGS     : ${CMAKE_C_FLAGS_DEBUG}
      C RELEASE FLAGS   : ${CMAKE_C_FLAGS_RELEASE}
      C++ standard      : ${CMAKE_CXX_STANDARD}
      C++ compiler      : ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}
      C++ FLAGS         : ${CMAKE_CXX_FLAGS}
      C++ DEBUG FLAGS   : ${CMAKE_CXX_FLAGS_DEBUG}
      C++ RELEASE FLAGS : ${CMAKE_CXX_FLAGS_RELEASE}
    Directory:
      Target install    : ${CMAKE_INSTALL_PREFIX}
      Library output    : ${LIBRARY_OUTPUT_PATH}
      Execute output    : ${EXECUTABLE_OUTPUT_PATH}
      Target archoutput : ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} 
      Target liboutput  : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} 
      Target execoutput : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
      Target build path : ${CMAKE_BINARY_DIR}
")

# build
add_subdirectory(hello_world)
add_subdirectory(thread_mng)



