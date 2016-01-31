#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

# define BUFF_SIZE 4096

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
	int 			id;
	int				x;
	int				y;
	int 			dist;
	int 			nb_ant;
	struct s_node	*next;
	struct s_link	*link;
}					t_node;

typedef struct 		s_ant
{
	int 			id;
	t_node			*node;
	struct s_ant	*next;
}					t_ant;

typedef struct 		s_data
{
	int				ant;
	t_node			*graph;
	char			*start;
	char			*end;
	t_node			*n_start;
	t_node			*n_end;
	t_ant			*tabant;
}					t_data;

int 			ft_is_number(char *str, int i);
void			ft_generate_ant(t_data *d);

void			ft_print_node(t_node *n);
void			ft_print_data(t_data d);
void			ft_print_ant(t_ant ant, int space);

int				get_next_line(int const fd, char **line);

void			ft_list_push_back(t_lst **l, char *str);

void			ft_parse_data(t_lst **l, t_data *d);

void			ft_push_node(char *str, t_node **graph, int r);
void			ft_push_link(t_node *parent, t_node *child);
void 			ft_del_link(t_link **lst, char *link);

void			ft_start(t_data d);

int 			ft_count_link(t_node *n);
t_node			*ft_utmost(t_node *n, t_node *origin);

void			ft_make_graph(t_node *n);
int				ft_make_graph_fast(t_node *n);

t_node 			*ft_is_saved_room(char *str, t_node *graph);
int 			ft_is_name(char *str, int i);
int 			ft_is_node(char *str);
int 			ft_is_link(char *str, t_node *graph);

void			ft_error();
void 			ft_is_ant(char *str, t_data *d);
int 			ft_is_cmd(char *str);
void			ft_verif_double(t_lst *lst);
void			ft_verif_double_name(t_data *d);

#endif