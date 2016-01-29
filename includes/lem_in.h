#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

# define BUFF_SIZE 10

typedef struct		s_save
{
	int				fd_num;
	char			*rest;
	struct s_save	*next;
}					t_save;

typedef struct		s_line
{
	struct s_line	*next;
	char			*str;
	int				size;
}					t_line;

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*str;
}					t_lst;

typedef struct 		s_link
{
	struct s_node	*node;
	struct s_link	*next_l;
}					t_link;
 
typedef	struct  	s_node
{
	char			*name;
	int				x;
	int				y;
	int 			dist;
	struct s_node	*next;
	struct s_link	*link;
}					t_node;

typedef struct 		s_data
{
	int				ant;
	t_node			*graph;
	char			*start;
	char			*end;
}					t_data;

int					get_next_line(int const fd, char **line);
t_lst				*ft_create_line(char *str);
void				ft_list_push_back(t_lst **l, char *str);

void				ft_error(void);
void 				ft_is_ant(char *str, t_data *d);
int 				ft_is_name(char *str, int i);
int 				ft_is_number(char *str, int i);
int 				ft_is_node(char *str);

void				ft_parse_data(t_lst **l, t_data *d);
int 				ft_is_cmd(char *str);
void 				ft_special_cmd(t_lst *l, t_data *d);
t_node				*ft_create_node(char *str);

void				ft_print_data(t_data d);

t_node				*ft_create_node(char *str);
void				ft_push_node(char *str, t_node **graph);
t_link				*ft_create_link(t_node *child);
void				ft_push_link(t_node *parent, t_node *child);

int 				ft_is_link(char *str, t_node *graph);

#endif