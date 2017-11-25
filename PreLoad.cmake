find_program(NINJA ninja)
if ("${NINJA}")
    set (CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
endif()
