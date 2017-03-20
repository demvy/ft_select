cmake_minimum_required(VERSION 3.6)
project(ft_select)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")


set(SOURCE_FILES
    args_func.c
    helpful.c
    list_work.c
    main.c
    signals.c
    tem_func.c do_func.c show_func.c)

link_directories(libft)
add_executable(ft_select ${SOURCE_FILES})
target_link_libraries(ft_select libft.a)
