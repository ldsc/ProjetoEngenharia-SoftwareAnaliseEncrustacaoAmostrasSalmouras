cmake_minimum_required(VERSION 3.27)

# Nome do projeto
project(PrecipitationSimulator LANGUAGES CXX)

# Defini��o da vers�o do C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona todos os arquivos de cabe�alho e c�digo-fonte ao projeto
set(SOURCES
    CIons.cpp
    CSalt.cpp
    main.cpp
    CSalmoura.cpp
    CTabelaPropriedadesIons.cpp
    CMisturaSalmouras.cpp
    CSimuladorPrecipitacao.cpp
    CPlotPrecipitacao.cpp
)

set(HEADERS
    CIons.h
    CSalt.h
    CSalmoura.h
    CTabelaPropriedadesIons.h
    CMisturaSalmouras.h
    CSimuladorPrecipitacao.h
    CPlotPrecipitacao.h
)

# Cria��o do execut�vel
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Define o diret�rio de sa�da do execut�vel na pasta root
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Configura��es adicionais para warnings e otimiza��es
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX) # Ativa avisos no Visual Studio
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic) # Ativa avisos em GCC/Clang
endif()
