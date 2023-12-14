cmake_minimum_required(VERSION 3.0.0)
project(APC-Injection VERSION 0.1.0 LANGUAGES C)

enable_language(C ASM_MASM)

add_executable(${PROJECT_NAME} main.c syscalls.asm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
