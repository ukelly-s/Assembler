# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ukelly <ukelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 20:40:53 by ukelly            #+#    #+#              #
#    Updated: 2020/11/26 21:08:20 by ukelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
LIBFT_A = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra

LIBFT_DIR = libft


SRC_DIR = source
OBJ_DIR = obj

INCLUDE = -I./include
INCLUDE += -I./libft/inc

HEADERS = include/asm.h
HEADERS += include/asm_errors.h
HEADERS += include/lexer.h
HEADERS += include/op.h
HEADERS += include/op_struct.h


SRCS = main.c
SRCS_ASM = assembler/asm.c
SRCS_ASM += assembler/parse.c
SRCS_ASM += assembler/util.c
SRCS_ASM += assembler/parse_name_comment.c
SRCS_ASM += assembler/parse_clear_line.c
SRCS_ASM += assembler/parse_operation.c
SRCS_ASM += assembler/parse_mark.c
SRCS_ASM += assembler/translation_bytecode.c
SRCS_COMMON = common/ft_isdigit.c
SRCS_COMMON += common/ft_strtrim.c


SRCS_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
SRCS_ASM_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_ASM))
SRCS_COMMON_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_COMMON))

OBJS = $(SRCS:.c=.o)
OBJS_ASM = $(SRCS_ASM:.c=.o)
OBJS_COMMON = $(SRCS_COMMON:.c=.o)

OBJS_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS))
OBJS_ASM_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_ASM))
OBJS_COMMON_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_COMMON))

.PHONY: clean fclean all re make_lib

all: $(ASM)

$(LIBFT_A) : make_lib
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS_PATH))
	@mkdir -p $(dir $(OBJS_ASM_PATH))
	@mkdir -p $(dir $(OBJS_COMMON_PATH))

make_lib :
	$(MAKE) -C $(LIBFT_DIR)

$(ASM): $(LIBFT_A) $(OBJS_PATH) $(OBJS_ASM_PATH) $(OBJS_COMMON_PATH) $(HEADERS)
	$(CC) -o $@ $(OBJS_PATH) $(OBJS_ASM_PATH) $(OBJS_COMMON_PATH) $(LIBFT_A) $(INCLUDE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(CC) -o $@ -c $< $(INCLUDE) $(FLAGS)

clean :
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) -rf $(ASM)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: clean fclean all re make_lib
