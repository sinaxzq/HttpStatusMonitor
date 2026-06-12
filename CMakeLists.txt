cmake_minimum_required(VERSION 3.20)

project(HttpStatusMonitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.11.2
)

FetchContent_MakeAvailable(cpr)

add_executable(HttpStatusMonitor
    main.cpp
    HttpChecker.cpp 
    ResultFormatter.cpp
    StatusClassifier.cpp
)

target_link_libraries(HttpStatusMonitor PRIVATE cpr::cpr)

target_include_directories(HttpStatusMonitor PRIVATE include)

if(WIN32)
    add_custom_command(TARGET HttpStatusMonitor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:HttpStatusMonitor>
            $<TARGET_FILE_DIR:HttpStatusMonitor>
        COMMAND_EXPAND_LISTS
    )
endif()

enable_testing()

add_executable(ResultFormatterTests 
    tests/ResultFormatterTests.cpp 
    ResultFormatter.cpp
)

target_include_directories(ResultFormatterTests PRIVATE
    include
)

add_test(
    NAME ResultFormatterTests 
    COMMAND ResultFormatterTests
)

add_executable(StatusClassifierTests 
    tests/StatusClassifierTests.cpp 
    StatusClassifier.cpp
)

target_include_directories(StatusClassifierTests PRIVATE
    include
)

add_test(
    NAME StatusClassifierTests 
    COMMAND StatusClassifierTests
)


