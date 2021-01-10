cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS " -Wall -Wextra")

include_directories(includes include)
include_directories(includes libft/inc)

add_library(libft STATIC
        libft/src/array_list/arrlist_new.c
        libft/src/array_list/arrlist_peek.c
        libft/src/array_list/arrlist_pop.c
        libft/src/array_list/arrlist_push.c
        libft/src/array_list/arrlist_util.c
        libft/src/array_list/arrlisti_new.c
        libft/src/array_list/arrlisti_peek.c
        libft/src/array_list/arrlisti_pop.c
        libft/src/array_list/arrlisti_push.c
        libft/src/array_list/arrlisti_utils.c
        libft/src/conv/ft_atol.c
        libft/src/hash_map/hash_map_destroy.c
        libft/src/hash_map/hash_map_get.c
        libft/src/hash_map/hash_map_iterate.c
        libft/src/hash_map/hash_map_new.c
        libft/src/hash_map/hash_map_put.c
        libft/src/hash_map/hash_map_resize.c
        libft/src/hash_map/hash_map_utils.c
        libft/src/io/ft_putendl.c
        libft/src/io/ft_putnbr.c
        libft/src/io/ft_putstr.c
        libft/src/io/get_next_line.c
        libft/src/list/list_clear.c
        libft/src/list/list_new.c
        libft/src/list/list_pop.c
        libft/src/list/list_push.c
        libft/src/math/ft_min.c
        libft/src/mem/memalloc.c
        libft/src/mem/memchr.c
        libft/src/mem/memcmp.c
        libft/src/mem/memcpy.c
        libft/src/mem/memmem.c
        libft/src/mem/memset.c
        libft/src/mem/memswap.c
        libft/src/string/ft_chars_count.c
        libft/src/string/ft_free_split.c
        libft/src/string/ft_isint.c
        libft/src/string/ft_strchr.c
        libft/src/string/ft_strdup.c
        libft/src/string/ft_strequ.c
        libft/src/string/ft_strjoin.c
        libft/src/string/ft_strlen.c
        libft/src/string/ft_strndup.c
        libft/src/string/ft_strnlen.c
        libft/src/string/ft_strsplit.c
        libft/src/string/ft_words_count.c
        libft/src/util/ft_assert.c
        libft/src/util/ft_kill.c
        libft/src/util/ft_log_error.c)

set_target_properties(libft PROPERTIES PUBLIC_HEADER
        libft/inc/array_list.h
        libft/inc/conv.h
        libft/inc/hash_map.h
        libft/inc/io.h
        libft/inc/list.h
        libft/inc/math.h
        libft/inc/mem.h
        libft/inc/str.h
        libft/inc/util.h)

add_executable(assembler $<TARGET_OBJECTS:libft>
        source/main.c
        source/assembler/parse.c
        source/assembler/asm.c
        source/assembler/util.c
        source/common/ft_strtrim.c
        source/assembler/parse_name_comment.c
        source/assembler/parse_clear_line.c
        source/assembler/debug.c
        source/assembler/find_cmd.c
        source/assembler/labeler.c
        source/assembler/labelfind.c
        source/assembler/labels.c
        source/assembler/lex.c
        source/assembler/lib.c
        source/assembler/live.c
        source/assembler/parse_operation.c)