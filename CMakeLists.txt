cmake_minimum_required(VERSION 3.20)
project(Thunder LANGUAGES C CXX ASM_MASM)

# ===============================
# Global
# ===============================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT WIN32)
    message(FATAL_ERROR "Windows only")
endif()

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "x64 only")
endif()

# ===============================
# Output
# ===============================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/Lib)

# ===============================
# Thunder sources
# ===============================
file(GLOB_RECURSE THUNDER_SOURCES
    source/*.cpp
    source/*.h
)

set(THUNDER_ASM source/spoof.asm)

# ===============================
# MinHook (STATIC Release)
# ===============================
add_library(MinHook STATIC
    source/minhook-master/src/buffer.c
    source/minhook-master/src/hook.c
    source/minhook-master/src/trampoline.c
    source/minhook-master/src/hde/hde32.c
    source/minhook-master/src/hde/hde64.c
)

target_include_directories(MinHook PUBLIC
    source/minhook-master/include
)

target_compile_definitions(MinHook PRIVATE
    MH_STATIC
    _CRT_SECURE_NO_WARNINGS
    NDEBUG
)

target_compile_options(MinHook PRIVATE
    /MT /O2 /GS-
)

set_target_properties(MinHook PROPERTIES
    OUTPUT_NAME "libMinHook.x64"
)

# ===============================
# Thunder DLL
# ===============================
add_library(Thunder SHARED
    ${THUNDER_SOURCES}
    ${THUNDER_ASM}
)

target_precompile_headers(Thunder PRIVATE source/stdafx.h)

target_include_directories(Thunder PRIVATE
    source
    source/minhook-master/include
)

target_compile_definitions(Thunder PRIVATE
    _WINDOWS
    _USRDLL
)

target_compile_options(Thunder PRIVATE
    /W3
    $<$<CONFIG:Debug>:/Od /Zi>
    $<$<CONFIG:Release>:/O2 /GL>
)

target_link_options(Thunder PRIVATE
    $<$<CONFIG:Release>:/OPT:REF /OPT:ICF /LTCG>
)

target_link_libraries(Thunder PRIVATE
    MinHook
    Ws2_32.lib
    Crypt32.lib
    Normaliz.lib
    Wldap32.lib
)

# ===============================
# Output names
# ===============================
set_target_properties(Thunder PROPERTIES
    OUTPUT_NAME_DEBUG ThunderMenu
    OUTPUT_NAME_RELEASE ExploitMenu
)
