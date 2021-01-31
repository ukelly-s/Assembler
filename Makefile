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
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft


SRC_DIR = source
OBJ_DIR = obj

INCLUDE = -I./include
INCLUDE += -I./libft/inc

HEADERS = include/asm.h
HEADERS += include/asm_errors.h
HEADERS += include/op.h
HEADERS += include/op_struct.h


SRCS = main.c
SRCS += ft_strtrim.c
SRCS_ASM = assembler/asm.c
SRCS_ASM += assembler/parse.c
SRCS_ASM += assembler/util.c
SRCS_ASM += assembler/parse_name_comment.c
SRCS_ASM += assembler/parse_clear_line.c
SRCS_ASM += assembler/parse_operation.c
SRCS_ASM += assembler/parse_mark.c
SRCS_ASM += assembler/big_endian_realisation.c
SRCS_ASM += assembler/translation_bytecode.c
SRCS_ASM += assembler/free.c


SRCS_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
SRCS_ASM_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_ASM))

OBJS = $(SRCS:.c=.o)
OBJS_ASM = $(SRCS_ASM:.c=.o)

OBJS_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS))
OBJS_ASM_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_ASM))

.PHONY: clean fclean all re make_lib

all: $(ASM)

$(LIBFT_A) : make_lib
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS_PATH))
	@mkdir -p $(dir $(OBJS_ASM_PATH))

make_lib :
	$(MAKE) -C $(LIBFT_DIR)

$(ASM): $(LIBFT_A) $(OBJS_PATH) $(OBJS_ASM_PATH) $(HEADERS)
	$(CC) -o $@ $(OBJS_PATH) $(OBJS_ASM_PATH) $(LIBFT_A) $(INCLUDE)

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
