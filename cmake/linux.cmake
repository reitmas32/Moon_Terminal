########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(TEMPLATE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/template)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
    ##TODO: Eliminar de aqui o incluir las cabeceras de spdlog de otro forma
    ${TEMPLATE_DIR}
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
########################
#    Find Source of    #
#       Project        #
########################
file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )

########################
#     Add Source of    #
#       Library        #
########################
add_library(
    ${NAME_LIB}
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)
########################
# Add Linker Libraries #
########################
TARGET_LINK_LIBRARIES( ${NAME_LIB}
    pthread
)

#includes de las bibliotecas de las que depende moon
#include(cmake/vendor.cmake)