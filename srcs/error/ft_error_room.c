#include "lem_in.h"

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

int 	ft_is_name(char *str, int i)
{
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	return (i);
}

int 	ft_is_node(char *str)
{
	int 	i;
	int 	s;
	int 	j;
	int 	ret;

	i = 0;
	j = 2;
	s = 0;
	ret = 0;
	if (*str)
	{
		if ((ret = ft_is_name(str, i)) == 0)
			return (0);
		i += ret;
		if ((ret = ft_is_number(str, i)) == 0)
			return (0);
		i += ret;
		if ((ret = ft_is_number(str, i)) == 0)
			return (0);
		i += ret;
		if (str[i])
			return (0);
	}
	else
		return (0);
	return (1);
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
	ft_strdel(&parent);
	ft_strdel(&child);
	ft_push_link(n_parent, n_child);
	ft_push_link(n_child, n_parent);
	return (1);
}