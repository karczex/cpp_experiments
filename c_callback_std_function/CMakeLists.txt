cmake_minimum_required(VERSION 3.3)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
########################### Clangd support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

############################ Sanitizers
option(Use_AddressSanitizer  "enable AddressSanitizer (debugging)" OFF)
option(Use_UndefinedBehaviorSanitizer "enable UndefinedBehaviorSanitizer (debugging)" OFF)

include(CheckCXXCompilerFlag)

macro(add_sanitizer_flag flag)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${flag}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${flag}")
endmacro()

if(Use_AddressSanitizer)
        add_sanitizer_flag(address)
endif()
if(Use_UndefinedBehaviorSanitizer)
        add_sanitizer_flag(undefined)
endif()


###########################  Executables


add_executable(main main.cpp)

add_library(mylib SHARED mylib.c )

target_link_libraries(main PRIVATE mylib)


