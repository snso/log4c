
#Project Make
cmake_minimum_required(VERSION 2.8)


SET(project_name runLog)
PROJECT(${project_name})


#Set Build Target System
SET(CMAKE_SYSTEM_NAME Linux)
# SET(CMAKE_SYSTEM_NAME Android)


#Set Build Type
SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_BUILD_TYPE "release")

if(CMAKE_SYSTEM_NAME MATCHES "Android")
	SET(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pie  -fPIE -std=gnu++11")
	SET(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pie -fPIE -std=gnu++11 -fvisibility=hidden")
	SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pie  -fPIE -std=gnu++11")
	SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pie -fPIE -std=gnu++11 -fvisibility=hidden")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	SET(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
	SET(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fvisibility=hidden")
	SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=gnu++11")
	SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=gnu++11 -fvisibility=hidden")
endif()

#Choose Compiler
if(CMAKE_SYSTEM_NAME MATCHES "Android")
	MESSAGE(STATUS "target-----Android")
	SET(CMAKE_C_COMPILER "aarch64-linux-android-gcc")
	SET(CMAKE_CXX_COMPILER "aarch64-linux-android-g++")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "target-----Linux")
	SET(CMAKE_C_COMPILER "gcc")
	SET(CMAKE_CXX_COMPILER "g++")
endif()

MESSAGE(STATUS "path = " ${PROJECT_SOURCE_DIR})


MESSAGE(STATUS "Target C Compiler : ${CMAKE_C_FLAGS_DEBUG}")
MESSAGE(STATUS "Compiler Flags: ${CMAKE_C_FLAGS_RELEASE}")

#include path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

#source directory
AUX_SOURCE_DIRECTORY( ${PROJECT_SOURCE_DIR} Src)


#set target lib property
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/run)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Link Libraries
if(CMAKE_SYSTEM_NAME MATCHES "Android")
	SET(LINK_LIB 	/usr/local/android/log4c/lib/liblog4c.so)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	SET(LINK_LIB 	/usr/local/lib/liblog4c.so)
endif()



# ${PROJECT_SOURCE_DIR}/lib/x2struct/thirdparty/libbson/lib/libbson-1.0.a
				
#Add Executable
# add_library(log4c SHARED ${ConfigSrc} ${Log4cSrc} ${LogSdSrc})

#add executable file
ADD_EXECUTABLE(${project_name} ${Src})

# add link library
TARGET_LINK_LIBRARIES(${project_name} ${LINK_LIB})

