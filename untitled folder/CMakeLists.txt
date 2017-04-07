cmake_minimum_required(VERSION 3.6)
project(ft_select)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES
    args_func.c
    ft_select.h
    helpful.c
    libft.a
    list_work.c
    main.c
    signals.c
    tem_func.c
    term_func.c)

add_executable(ft_select ${SOURCE_FILES})
target_link_libraries(ft_select ${CMAKE_SOURCE_DIR}/libft.a)