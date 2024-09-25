NAME = libftprintf.a
CFILES = ft_printf.c ft_printnumb.c ft_helpers.c ft_printhex.c

OFILES = $(CFILES:.c=.o)


CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)



%.o: %.c %.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re

