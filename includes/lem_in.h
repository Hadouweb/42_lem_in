/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:40:56 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 09:40:58 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define BUFF_SIZE 4096

typedef struct s_save	t_save;
typedef struct s_line	t_line;
typedef struct s_lst	t_lst;
typedef struct s_link	t_link;
typedef	struct s_node	t_node;
typedef struct s_ant	t_ant;
typedef struct s_option	t_option;
typedef struct s_data	t_data;

struct				s_save
{
	int				fd_num;
	char			*rest;
	t_save			*next;
};

struct				s_line
{
	t_line			*next;
	char			*str;
	int				size;
};

struct				s_lst
{
	t_lst			*next;
	char			*str;
};

struct				s_link
{
	t_node			*node;
	t_link			*next_l;
};

struct				s_node
{
	char			*name;
	int				id;
	int				x;
	int				y;
	int				dist;
	int				nb_ant;
	int				used;
	t_node			*next;
	t_link			*link;
};

struct				s_ant
{
	int				id;
	t_node			*node;
	t_ant			*next;
};

struct				s_option
{
	char			h;
	char			e;
	char			r;
	char			o;
	char			s;
	char			g;
	char			a;
	char			l;
};

struct				s_data
{
	int				ant;
	char			*tmp_ant;
	t_node			*graph;
	char			*start;
	char			*end;
	int				step;
	t_node			*n_start;
	t_node			*n_end;
	t_ant			*tabant;
	t_option		opt;
};

int					ft_is_number(char *str, int i);
void				ft_generate_ant(t_data *d);

void				ft_print_node(t_node *n, t_data d);
void				ft_print_data(t_data d);
void				ft_print_ant(t_ant ant, int space);

int					get_next_line(int const fd, char **line);

void				ft_list_push_back(t_lst **l, char *str);

void				ft_parse_data(t_lst **l, t_data *d);

void				ft_push_node(char *str, t_node **graph, int r);
void				ft_push_link(t_node *parent, t_node *child);
void				ft_del_link(t_link **lst, char *link);

void				ft_start(t_data *d);

int					ft_count_link(t_node *n);
t_node				*ft_utmost(t_node *n, t_node *origin);

void				ft_make_graph(t_node *n);
int					ft_make_graph_fast(t_node *n);

t_node				*ft_is_saved_room(char *str, t_node *graph);
int					ft_is_name(char *str, int i);
int					ft_is_node(char *str);
int					ft_is_link(char *str, t_node *graph);

void				ft_error(char *str, t_data d);
void				ft_is_ant(char *str, t_data *d);
int					ft_is_cmd(char *str);
void				ft_verif_double(t_lst *lst, t_data d);
void				ft_verif_double_name(t_data *d);

t_node				*ft_get_start_node(t_node *node, t_node *end);
int					ft_move(t_ant *ant, t_data d, int *space);
int					ft_use_map(t_lst **lst);

void				ft_print_options(void);
void				ft_parse_options(char *options, t_data *d);
void				ft_print_road(t_data *d);
void				ft_options(t_data *d);
void				ft_get_start_end(t_data *d);
t_node				*ft_get_the_smallest_verify(t_link *link, t_node *sml);
t_node				*ft_get_the_smallest(t_link *link);

#endif
