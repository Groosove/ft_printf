NAME = libftprintf.a

INCLUDE = ft_printf.h

SRC = ft_bonus.c ft_printf.c ft_print_number.c libft.c \
		ft_print_char.c ft_print_number.c ft_itoa_precision.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror
.c.o:
	@gcc -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(INCLUDE)
	@ar rcs $(NAME) $(OBJ)
	@echo "Good)"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "CLEAN"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
