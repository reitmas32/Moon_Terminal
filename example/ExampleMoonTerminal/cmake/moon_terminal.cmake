#########################
#       Lib Moon        #
#########################
if(${WIN32})

elseif(${UNIX})
set(MOON_TERMINAL_INCLUDE_DIR 
${CMAKE_SOURCE_DIR}/vendor
${CMAKE_SOURCE_DIR}/vendor/Moon_Terminal/include )

set(MOON_TERMINAL_LIBRARIES ncurses)

endif()