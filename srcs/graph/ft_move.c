#include "lem_in.h"

static t_node	*ft_get_best_node(t_node *node, t_node *start, t_node *end)
{
	t_link	*link;
	t_node	*best;

	link = node->link;
	best = NULL;
	if (node->link)
	{
		best = NULL;
		while (link && !best)
		{
			if (link->node->nb_ant == 0 && ft_strcmp(link->node->name, start->name) != 0 && link->node->dist != 0 
				&& link->node->dist < node->dist)
				best = link->node;
			if (ft_strcmp(link->node->name, end->name) == 0) 
				return (link->node);
			link = link->next_l;
		}
		link = node->link;
		if (best)
		{
			while (link)
			{
				if (link->node->nb_ant == 0 && ft_strcmp(link->node->name, start->name) != 0 &&
					link->node->dist < best->dist && link->node->dist != 0)
					best = link->node;
				link = link->next_l;
			}
		}
	}
	return (best);
}

static t_node	*ft_get_the_smallest(t_link *link)
{
	t_link	*l;
	t_node	*sml;

	l = link;
	sml = NULL;
	if (l)
	{
		while (l)
		{
			if ((sml == NULL || l->node->dist < sml->dist) && l->node->dist != 0)
				sml = l->node;
			l = l->next_l;
		}
		if (sml != NULL)
		{
			l = link;
			while (l)
			{
				if (l->node->dist == sml->dist && l->node->dist != 0 && l->node->nb_ant == 0)
					sml = l->node;
				l = l->next_l;
			}
		}
	}
	return (sml);
}

static t_node	*ft_get_start_node(t_node *node, t_node *end)
{
	t_link	*link;
	t_node	*best;
	int 	i;

	link = node->link;
	best = NULL;
	i = 0;
	if (node->link)
	{
		best = NULL;
		while (link)
		{

			if (link->node->dist != 0 && link->node->nb_ant == 0 &&
				(best == NULL || link->node->dist < best->dist) &&
				node->nb_ant >= link->node->dist)
				best = link->node;
			if (ft_strcmp(link->node->name, end->name) == 0) 
				return (link->node);
			link = link->next_l;
		}
		if (!best)
		{
			best = ft_get_the_smallest(node->link);
		}
		if (best && best->nb_ant != 0)
			best = NULL;
	}
	return (best);
}

static int 		ft_move(t_ant *ant, t_data d, int *space)
{
	t_node	*best_node;
	int 	forward;

	forward = 0;
	best_node = NULL;
	if (ft_strcmp(ant->node->name, d.n_end->name) != 0)
	{
		if (ft_strcmp(ant->node->name, d.n_start->name) == 0)
			best_node = ft_get_start_node(ant->node, d.n_end);
		else
			best_node = ft_get_best_node(ant->node, d.n_start, d.n_end);
		if (best_node)
		{
			ant->node->nb_ant -= 1;
			best_node->nb_ant += 1;
			ant->node = best_node;
			forward = 1;
			ft_print_ant(*ant, *space);
			*space = 1;
		}
	}
	return (forward);
}

void			ft_start(t_data d)
{
	t_ant	*ant;
	int 	i;
	int 	forward;
	int 	space;
	int 	j;

	i = 0;
	forward = 1;
	ant = d.tabant;
	j = 0;
	while (forward && d.n_end->nb_ant != d.ant)
	{
		forward = 0;
		i = 0;
		space = 0;
		while (i < d.ant)
		{
			forward += ft_move(&ant[i], d, &space);
			i++;
		}
		if (forward)
			ft_putstr("\n");
		i = 0;
	}
}
