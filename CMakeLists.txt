cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/$<CONFIG> ${CMAKE_SOURCE_DIR}
)


# if you are building in-source, this is the same as CMAKE_SOURCE_DIR, otherwise
# this is the top level directory of your build tree
MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )

# if you are building in-source, this is the same as CMAKE_CURRENT_SOURCE_DIR, otherwise this
# is the directory where the compiled or generated files from the current CMakeLists.txt will go to
MESSAGE( STATUS "CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR} )

# this is the directory, from which cmake was started, i.e. the top level source directory
MESSAGE( STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR} )

# this is the directory where the currently processed CMakeLists.txt is located in
MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )

# contains the full path to the top level directory of your build tree
MESSAGE( STATUS "PROJECT_BINARY_DIR: " ${PROJECT_BINARY_DIR} )

# contains the full path to the root of your project source directory,
# i.e. to the nearest directory where CMakeLists.txt contains the PROJECT() command
MESSAGE( STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR} )
MESSAGE( STATUS "EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH} )
MESSAGE( STATUS "CMAKE_BUILD_TYPE : " ${CMAKE_BUILD_TYPE} )
MESSAGE( STATUS "CMAKE_CONFIGURATION_TYPES : " ${CMAKE_CONFIGURATION_TYPES} )


MESSAGE( STATUS "CMAKE_ROOT : " ${CMAKE_ROOT} )
MESSAGE( STATUS "CMAKE_BINARY_DIR : " ${CMAKE_BINARY_DIR} )
MESSAGE( STATUS "PROJECT_BINARY_DIR : " ${PROJECT_BINARY_DIR} )
MESSAGE( STATUS "RUNTIME_OUTPUT_DIRECTORY : " ${RUNTIME_OUTPUT_DIRECTORY} )


MESSAGE( STATUS "VS_CONFIGURATION_TYPE : " ${VS_CONFIGURATION_TYPE} )
MESSAGE( STATUS "VS_COPY_TO_OUT_DIR : " ${VS_COPY_TO_OUT_DIR} )
MESSAGE( STATUS "VS_DEPLOYMENT_LOCATION : " ${VS_DEPLOYMENT_LOCATION} )