NAME = test
SRC = ./source/main.c\
	./source/common/ft_strtrim.c\
	./source/assembler/util.c\
	./source/assembler/asm.c\
	./source/assembler/parse.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
INC = -I ./include -I ./libft/inc
LIBFT = ./libft/libft.a
COMP =  $(CC) $(FLAGS) $(SRC)  -o $(NAME)
2COMP = $(CC) -g $(SRC) $(LIBFT) $(INC) -o $(NAME)

all:
	$(2COMP)

clean:
	rm $(NAME)