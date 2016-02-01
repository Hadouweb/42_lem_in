#include "lem_in.h"

t_node	*ft_get_the_smallest_verify(t_link *link, t_node *sml)
{
	t_link	*l;
	t_node	*tmp;

	l = link;
	tmp = NULL;
	while (l)
	{
		if (l->node->dist == sml->dist && l->node->dist != 0 &&
			l->node->nb_ant == 0)
			tmp = l->node;
		l = l->next_l;
	}
	return (tmp);
}

t_node	*ft_get_the_smallest(t_link *link)
{
	t_link	*l;
	t_node	*sml;

	l = link;
	sml = NULL;
	if (l)
	{
		while (l)
		{
			if ((sml == NULL || l->node->dist < sml->dist) &&
				l->node->dist != 0)
				sml = l->node;
			l = l->next_l;
		}
		if (sml != NULL)
			sml = ft_get_the_smallest_verify(link, sml);
	}
	return (sml);
}