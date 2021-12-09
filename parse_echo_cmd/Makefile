CFLAGS = -Wall -Wextra #-Werror

CC = clang

NAME = ms

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

flemme: re
	make clean

.PHONY: clean fclean all re
