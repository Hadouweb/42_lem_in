#include "lem_in.h"

int 	ft_count_link(t_node *n)
{
	t_link 	*l;
	int 	i;

	i = 0;
	l = n->link;
	while (l)
	{
		i++;
		l = l->next_l;
	}
	return (i);
}

t_node	*ft_utmost(t_node *n, t_node *origin)
{
	t_link 	*l;
	t_node 	*utmost;

	l = n->link;
	utmost = NULL;
	while (l)
	{
		if (ft_strcmp(origin->name, l->node->name) != 0 && 
			(utmost == NULL || l->node->dist < utmost->dist))
			utmost = l->node;
		l = l->next_l;
	}
	return (utmost);
}

