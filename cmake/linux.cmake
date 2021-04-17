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
    ${TEMPLATE_DIR}
    ##TODO: Incluir los directoriosde Moon de otra forma
    ##TODO: Tal ves lo mejor es poner Moon-Core y Pluggins en opt dir
    /home/rafa/git/Moon_Terminal/example/ExampleMoonTerminal/vendor
    /home/rafa/git/Moon_Terminal/example/ExampleMoonTerminal/vendor/Moon/include
    /home/rafa/git/Moon_Terminal/example/ExampleMoonTerminal/vendor/Moon/template
    /home/rafa/git/Moon_Terminal/example/ExampleMoonTerminal/vendor/Moon/vendor
    /home/rafa/git/Moon_Terminal/example/ExampleMoonTerminal/vendor/Moon/vendor/termcolor

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