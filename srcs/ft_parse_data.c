#include "lem_in.h"

t_node	*ft_create_node(char *str)
{
	t_node	*node;
	int 	ret;

	ret = 0;
	node = (t_node*)ft_memalloc(sizeof(t_node));
	node->name = ft_strdup_limit(str, ' ');
	ret += ft_strlen_limit(&str[ret], ' ') + 1;
	node->x = ft_atoi(&str[ret]);
	ret += ft_strlen_limit(&str[ret], ' ') + 1;
	node->y = ft_atoi(&str[ret]);
	node->dist = 0;
	node->link = NULL;
	return (node);
}

void	ft_push_node(char *str, t_node **graph)
{

	t_node	*n;

	n = *graph;
	printf("%p\n", graph);
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = ft_create_node(str);
	}
	else
	{
		*graph = ft_create_node(str);
	}
}

t_link	*ft_create_link(t_node *child)
{
	t_link	*link;

	link = (t_link*)ft_memalloc(sizeof(t_link));
	link->node = child;
	return (link);
}

void	ft_push_link(t_node *parent, t_node *child)
{
	t_link	*link;

	link = parent->link;
	if (link)
	{
		while (link->next_l)
			link = link->next_l;
		link->next_l = ft_create_link(child);
	}
	else
		parent->link = ft_create_link(child);
}

t_node 	*ft_is_saved_room(char *str, t_node *graph)
{
	t_node	*g;
	t_node	*n;

	g = graph;
	n = NULL;
	while (g)
	{
		if (ft_strcmp(str, g->name) == 0)
			n = g;
		g = g->next;
	}
	return (n);
}

int 	ft_is_link(char *str, t_node *graph)
{
	char	*parent;
	char	*child;
	t_node	*n_parent;
	t_node	*n_child;
	int 	i;

	parent = ft_strdup_limit(str, '-');
	n_parent = NULL;
	n_child = NULL;
	if (parent)
	{
		if ((n_parent = ft_is_saved_room(parent, graph)) == NULL)
			return (0);
	}
	i = ft_strlen_limit(str, '-');
	if (str[i] != '-')
		return (0);
	i++;
	child = ft_strdup_limit(&str[i], '-');
	if (child)
	{
		if ((n_child = ft_is_saved_room(child, graph)) == NULL)
			return (0);
	}
	ft_push_link(n_parent, n_child);
	ft_push_link(n_child, n_parent);
	return (1);
}

void	ft_parse_data(t_lst **l, t_data *d)
{
	int 	i;
	int 	cmd;
	t_lst	*lst;

	i = 0;
	cmd = 0;
	lst = *l;
	printf("%p\n", &d->graph);
	while (lst)
	{
		//printf("%s [%d]\n", lst->str, i);

		if (i == 0)
			ft_is_ant(lst->str, d);
		else if (ft_is_cmd(lst->str) == 2)
			ft_special_cmd(lst, d);
		else if (ft_is_node(lst->str))
			ft_push_node(lst->str, &d->graph);
		//else if (ft_is_link(lst->str, d.graph))
		//	;
		lst = lst->next;
		i++;
	}
	printf("%p\n", &d->graph);
	ft_print_data(*d);
}

int 	ft_is_cmd(char *str)
{
	int 	i;

	i = 0;
	while (str[i] && str[i] == '#')
		i++;
	return (i);
}

void 	ft_special_cmd(t_lst *l, t_data *d)
{
	if (ft_strcmp(l->str, "##start") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error("The ##start room is invalid", l->next->str);
		d->start = ft_strdup(l->str);
	}
	else if (ft_strcmp(l->str, "##end") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error("The ##end room is invalid", l->next->str);
		d->end = ft_strdup(l->str);
	}
}