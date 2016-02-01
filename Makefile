CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs
ERRORPATH = $(SRCPATH)/error
SAVEPATH = $(SRCPATH)/save
UTILPATH = $(SRCPATH)/util
GRAPHPATH = $(SRCPATH)/graph
INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)/

LIB = $(LIBFT)/libft.a

SRC = 	$(SRCPATH)/main.c\
		$(SAVEPATH)/get_next_line.c\
		$(SAVEPATH)/ft_parse_data.c\
		$(SAVEPATH)/ft_list_room.c\
		$(SAVEPATH)/ft_read_data.c\
		$(ERRORPATH)/ft_error.c\
		$(ERRORPATH)/ft_error_room.c\
		$(UTILPATH)/ft_util.c\
		$(UTILPATH)/ft_debug.c\
		$(UTILPATH)/ft_gen.c\
		$(UTILPATH)/ft_options.c\
		$(GRAPHPATH)/ft_make_graph.c\
		$(GRAPHPATH)/ft_make_util.c\
		$(GRAPHPATH)/ft_move.c\
		$(GRAPHPATH)/ft_move_util.c\

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
