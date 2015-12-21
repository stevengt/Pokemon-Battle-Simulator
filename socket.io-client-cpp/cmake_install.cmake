# Install script for directory: /Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/include/sio_client.h;/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/include/sio_message.h;/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/include/sio_socket.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/include" TYPE FILE FILES
    "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/src/sio_client.h"
    "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/src/sio_message.h"
    "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/src/sio_socket.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release" TYPE STATIC_LIBRARY FILES "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/libsioclient.a")
  if(EXISTS "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient_tls.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release" TYPE STATIC_LIBRARY FILES "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/libsioclient_tls.a")
  if(EXISTS "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient_tls.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient_tls.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libsioclient_tls.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libboost_system-mt.a;/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libboost_date_time-mt.a;/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release/libboost_random-mt.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/build/lib/Release" TYPE FILE FILES
    "/usr/local/lib/libboost_system-mt.a"
    "/usr/local/lib/libboost_date_time-mt.a"
    "/usr/local/lib/libboost_random-mt.a"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/stevengt/Downloads/of_v0.9.0_osx_release/apps/myApps/Pokemon-Battle-Simulator/socket.io-client-cpp/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
