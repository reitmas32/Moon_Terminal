#########################
#       Lib Moon        #
#########################
if(${WIN32})

elseif(${UNIX})
set(MOON_TERMINAL_INCLUDE_DIR 
${CMAKE_SOURCE_DIR}/vendor
${CMAKE_SOURCE_DIR}/vendor/Moon_Terminal/include )

option(LOGS "ON")
if(${LOGS} STREQUAL "OFF")
    add_compile_definitions(RELEASE)
    set(MOON_TERMINAL_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon_Terminal/build/libmoon_terminal.a ncurses)
else()
    set(MOON_TERMINAL_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon_Terminal/build/libmoon_terminal.a ncurses)
endif()
endif()