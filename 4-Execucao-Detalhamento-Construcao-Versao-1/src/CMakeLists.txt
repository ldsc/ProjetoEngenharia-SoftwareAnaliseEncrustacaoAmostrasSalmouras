cmake_minimum_required(VERSION 3.27)

# Nome do projeto
project(PrecipitationSimulator LANGUAGES CXX)

# Definição da versão do C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona todos os arquivos de cabeçalho e código-fonte ao projeto
set(SOURCES
    CThermodynamicConditions.cpp
    CIons.cpp
    CSalt.cpp
    main.cpp
    CSalmoura.cpp
    CTabelaPropriedadesIons.cpp
    CMisturaSalmouras.cpp
    CSimuladorPrecipitacao.cpp
)

set(HEADERS
    CThermodynamicConditions.h
    CIons.h
    CSalt.h
    CSalmoura.h
    CTabelaPropriedadesIons.h
    CMisturaSalmouras.h
    CSimuladorPrecipitacao.h
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
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror) # Ativa avisos em GCC/Clang
endif()
