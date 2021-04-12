#########################
#       Lib Moon        #
#########################
if(${WIN32})
    add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/Moon)

    set(MOON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/Moon/include ${CMAKE_SOURCE_DIR}/vendor/Moon/template ${CMAKE_SOURCE_DIR}/vendor/Moon/vendor/termcolor)
    set(MOON_LIBRARIES ${MOON_LIBRARIES} moon)
    
    option(LOGS "ON")
    if(${LOGS} STREQUAL "OFF")
        add_compile_definitions(RELEASE)
    endif()

elseif(${UNIX})
    set(MOON_INCLUDE_DIR 
        ${CMAKE_SOURCE_DIR}/vendor 
        ${CMAKE_SOURCE_DIR}/vendor/Moon/template 
        ${CMAKE_SOURCE_DIR}/vendor/Moon/include 
        ${CMAKE_SOURCE_DIR}/vendor/Moon/vendor/termcolor)
    option(LOGS "ON")
    if(${LOGS} STREQUAL "OFF")
        add_compile_definitions(RELEASE)
        set(MOON_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon/build/libmoon.a)
    else()
        set(MOON_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon/build/libmoon.a)
    endif()

endif()