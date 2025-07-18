cmake_minimum_required(VERSION 3.27)

# Nome do projeto
project(PrecipitationSimulator LANGUAGES CXX)

# Definição da versão do C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona todos os arquivos de cabeçalho e código-fonte ao projeto
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

# Criação do executável
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Define o diretório de saída do executável na pasta root
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Configurações adicionais para warnings e otimizações
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX) # Ativa avisos no Visual Studio
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic) # Ativa avisos em GCC/Clang
endif()
