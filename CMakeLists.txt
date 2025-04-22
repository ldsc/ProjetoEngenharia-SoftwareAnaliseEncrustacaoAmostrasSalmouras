cmake_minimum_required(VERSION 3.27)

# Software Incrustação - Állida e João
project(PrecipitationSimulator LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    ThermodynamicConditions.cpp
    CreateIons.cpp
    Salt.cpp
    PrecipitationCalculator.cpp
    Sandbox.cpp
)

set(HEADERS
    ThermodynamicConditions.h
    CreateIons.h
    Salt.h
    PrecipitationCalculator.h
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX) 
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror) 
endif()
