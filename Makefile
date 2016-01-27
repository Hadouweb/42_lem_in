CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs
INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)/

LIB = $(LIBFT)/libft.a

SRC = 	$(SRCPATH)/main.c\
		$(SRCPATH)/get_next_line.c\
		$(SRCPATH)/ft_save_data.c\

OBJ = $(SRC:.c=.o)

NAME = lem-in

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
