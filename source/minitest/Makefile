NAME = minitest

SRC = ./main.c\
	./debug.c\
	./find_cmd.c\
	./labeler.c\
	./lex.c\
	./lib.c\
	./live.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
LIBFT = ../../libft/libft.a
INC = -I ./ -I ../../libft/inc
COMP =  $(CC) $(FLAGS) $(SRC) -o $(NAME)
2COMP = $(CC) -g $(SRC) $(LIBFT) -o $(NAME)

all:
	$(2COMP)

clean:
	rm $(NAME)