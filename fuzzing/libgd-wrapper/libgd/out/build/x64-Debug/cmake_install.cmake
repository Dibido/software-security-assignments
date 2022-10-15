# Install script for directory: C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/docs/INSTALL")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/docs/README.JPN")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/docs/README.CMAKE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/docs/README.TESTING")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/docs/README.TXT")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/arc.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/copyrotated.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/crop.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/flip.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/gif.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/nnquant.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/noIcon.pic")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/noIcon.sgi")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/noIcon.tga")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/noIconAlpha.tga")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/test_crop_threshold.png")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/tgaread.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/tiffread.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gd-." TYPE FILE FILES "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/examples/windows.c")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/src/cmake_install.cmake")
  include("C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/tests/cmake_install.cmake")
  include("C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/examples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/seanh/Documents/Image Manipulation Project/Project/Source/Project/libgd/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
