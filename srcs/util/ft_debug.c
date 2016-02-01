/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:01:57 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:01:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 	ft_print_link(t_link *link)
{
	if (link)
		ft_putstr(" -> ");
	while (link)
	{
		ft_putstr("\e[45m ");
		ft_putstr("NAME: ");
		ft_putstr(link->node->name);
		ft_putstr(" | ID: [");
		ft_putnbr(link->node->id);
		ft_putstr("] | DIST: ");
		ft_putnbr(link->node->dist);
		if (link->next_l)
			ft_putstr(" \e[0m | ");
		link = link->next_l;
	}
	ft_putstr(" \e[0m");
}

void	ft_print_node(t_node *n, t_data d)
{
	ft_putstr("\e[44m NAME: ");
	ft_putstr(n->name);
	ft_putstr(" | ID: [");
	ft_putnbr(n->id);
	ft_putstr("] | DIST: ");
	ft_putnbr(n->dist);
	ft_putstr(" \e[0m");
	if (d.opt.l)
		ft_print_link(n->link);
	ft_putchar('\n');
}

void	ft_print_data(t_data d)
{
	t_node	*g;

	g = d.graph;
	ft_putstr("\n[DATA]\n");

	ft_putstr("[ANT] : ");
	ft_putnbr(d.ant);
	ft_putstr("\n[START] : ");
	ft_print_node(d.n_start, d);
	ft_putstr("\n[END] : ");
	ft_print_node(d.n_end, d);

	ft_putstr("\n[ROOMS]");
	while (g)
	{
		ft_putchar('\n');
		ft_print_node(g, d);
		g = g->next;
	}
}

void	ft_print_ant(t_ant ant, int space)
{
	if (space)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant.id + 1);
	ft_putchar('-');
	ft_putstr(ant.node->name);
}
