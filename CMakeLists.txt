cmake_minimum_required(VERSION 3.5)

project(coconut_example LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/Coconut)

set(EXCLUDE_PATHS
    "CMakeFiles"
)
file(GLOB_RECURSE CPP_FILES "*.cpp")

foreach(TMP_PATH ${CPP_FILES})
    foreach(EXCLUDE_PATH ${EXCLUDE_PATHS})
        string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT)

        if(NOT ${RESULT} EQUAL -1)
            list(REMOVE_ITEM CPP_FILES ${TMP_PATH})
        endif()
    endforeach(EXCLUDE_PATH)
endforeach(TMP_PATH)

foreach(TMP_PATH ${CPP_FILES})
message(STATUS "CPP_FILES : ${CPP_FILES}")
endforeach(TMP_PATH)

add_executable(${PROJECT_NAME} ${CPP_FILES})
