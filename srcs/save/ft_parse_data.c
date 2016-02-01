/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:02:58 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:02:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_special_cmd(t_lst *l, t_data *d)
{
	if (ft_strcmp(l->str, "##start") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error("Room start is invalid", *d);
		d->start = l->next->str;
	}
	else if (ft_strcmp(l->str, "##end") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error("Room end is invalid", *d);
		d->end = l->next->str;
	}
}

void		ft_get_start_end(t_data *d)
{
	t_node	*n;
	char	*start;
	char	*end;

	n = d->graph;
	start = ft_strdup_limit(d->start, ' ');
	end = ft_strdup_limit(d->end, ' ');
	while (n)
	{
		if (ft_strcmp(start, n->name) == 0)
		{
			d->n_start = n;
			d->n_start->id = -1;
		}
		if (ft_strcmp(end, n->name) == 0)
		{
			d->n_end = n;
			d->n_end->id = 0;
		}
		n = n->next;
	}
	ft_strdel(&start);
	ft_strdel(&end);
	d->n_start->nb_ant = d->ant;
}

void		ft_parse_data(t_lst **l, t_data *d)
{
	int		i;
	t_lst	*lst;
	int		m;
	int		r;

	i = 0;
	lst = *l;
	m = 0;
	r = 1;
	while (lst)
	{
		if (i++ == 0)
			ft_is_ant(lst->str, d);
		else if (ft_is_cmd(lst->str) == 2)
			ft_special_cmd(lst, d);
		else if (ft_is_node(lst->str) && m == 0 && r++)
			ft_push_node(lst->str, &d->graph, r);
		else if (ft_is_link(lst->str, d->graph) && ++m)
			;
		else if (ft_is_cmd(lst->str) > 0)
			;
		else
			ft_error(lst->str, *d);
		lst = lst->next;
	}
}
