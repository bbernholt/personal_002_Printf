CC=gcc 
CFLAGS=-Wall -Wextra -Werror


NAME=libftprintf.a
OBJECTS = $(CFILES:.c=.o)
CFILES=ft_putchar.c ft_putnbr.c ft_putstr.c ft_itoh.c ft_putunbr.c ft_printf.c

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