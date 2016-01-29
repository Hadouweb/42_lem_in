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