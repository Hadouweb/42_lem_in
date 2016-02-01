/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:03:35 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:03:36 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*ft_get_best_node_verify(t_node *node, t_node *start,
	t_node *best)
{
	t_link	*link;
	t_node	*tmp;

	link = node->link;
	tmp = best;
	while (link)
	{
		if (link->node->nb_ant == 0 && link->node->id != start->id &&
			link->node->dist < tmp->dist && link->node->dist != 0)
			tmp = link->node;
		link = link->next_l;
	}
	return (tmp);
}

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
			if (link->node->nb_ant == 0 && link->node->id != start->id &&
				link->node->dist != 0 && link->node->dist < node->dist)
				best = link->node;
			if (link->node->id == end->id)
				return (link->node);
			link = link->next_l;
		}
		if (best)
			best = ft_get_best_node_verify(node, start, best);
	}
	return (best);
}

t_node			*ft_get_start_node(t_node *node, t_node *end)
{
	t_link	*link;
	t_node	*best;

	link = node->link;
	best = NULL;
	if (node->link)
	{
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
			best = ft_get_the_smallest(node->link);
		if (best && best->nb_ant != 0)
			best = NULL;
	}
	return (best);
}

int				ft_move(t_ant *ant, t_data d, int *space)
{
	t_node	*best_node;
	int		forward;

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
			best_node->used = 1;
			ant->node = best_node;
			forward = 1;
			ft_print_ant(*ant, *space);
			*space = 1;
		}
	}
	return (forward);
}

void			ft_start(t_data *d)
{
	t_ant	*ant;
	int		i;
	int		forward;
	int		space;

	forward = 1;
	ant = d->tabant;
	while (forward && d->n_end->nb_ant != d->ant)
	{
		forward = 0;
		i = 0;
		space = 0;
		while (i < d->ant)
		{
			forward += ft_move(&ant[i], *d, &space);
			i++;
		}
		if (forward)
		{
			d->step += 1;
			ft_putstr("\n");
		}
		i = 0;
	}
}
