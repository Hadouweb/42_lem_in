#include "lem_in.h"

void	ft_make_graph(t_node *n)
{
	t_link	*link;

	link = n->link;
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist) && 
			link->node->id != 0 && link->node->id != -1)
		{
			link->node->dist = n->dist + 1;
			ft_make_graph(link->node);
		}
		link = link->next_l;
	}
}


int		ft_make_graph_fast(t_node *n)
{
	t_link	*link;

	if (!n)
		return (0);
	link = n->link;
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist) && 
			link->node->id != 0 && link->node->id != -1)
		{
			link->node->dist = n->dist + 1;
		}
		link = link->next_l;
	}
	return (ft_make_graph_fast(n->next));
}