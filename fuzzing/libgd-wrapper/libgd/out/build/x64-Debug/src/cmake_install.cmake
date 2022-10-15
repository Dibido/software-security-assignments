# Install script for directory: C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/Bin/gdcmpgif.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/Bin/libgd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/Bin/libgd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/bdftogd")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/entities.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gd.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gd_color_map.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gd_errors.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gd_io.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdcache.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfontg.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfontl.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfontmb.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfonts.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfontt.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdfx.h"
    "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/src/gdpp.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/src/gdlib.pc")
endif()

