CC=gcc 
CFLAGS=-Wall -Wextra -Werror


NAME=libftprintf.a
OBJECTS = $(CFILES:.c=.o)
CFILES=ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c

all:$(NAME)

$(NAME): $(OBJECTS)
	ar -crs $(NAME) $^

$(OBJECTS): $(CFILES) 
	$(CC) $(CLFAGS) -c $^

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re