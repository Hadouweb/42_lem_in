/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:01:52 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:01:54 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_options(void)
{
	ft_putstr("usage: lem-in [-herosg]\n\n");
	ft_putstr("\th : print this message help\n");
	ft_putstr("\te : print error message\n");
	ft_putstr("\tr : print all rooms used\n");
	ft_putstr("\to : print the solution quickly\n");
	ft_putstr("\ts : print the number of steps\n");
	ft_putstr("\tg : print the solution with random map (1-2000 rooms)\n");
	ft_putstr("\ta : force the number of ant : -a number\n");
	ft_putchar('\n');
	exit(1);
}

void		ft_add_option(char option, t_data *d)
{
	if (option == 'h')
		d->opt.h = 1;
	else if (option == 'e')
		d->opt.e = 1;
	else if (option == 'r')
		d->opt.r = 1;
	else if (option == 'o')
		d->opt.o = 1;
	else if (option == 's')
		d->opt.s = 1;
	else if (option == 'g')
		d->opt.g = 1;
	else if (option == 'a')
		d->opt.a = 1;
	else if (option == 'l')
		d->opt.l = 1;
	else
	{
		ft_putstr("lem-in: illegal option\n");
		ft_print_options();
	}
}

void		ft_parse_options(char *options, t_data *d)
{
	int		i;

	i = 0;
	if (options[0] != '-')
	{
		ft_putstr("lem-in: illegal option\n");
		ft_print_options();
	}
	else
	{
		i++;
		while (options[i])
		{
			ft_add_option(options[i], d);
			i++;
		}
	}
}

void		ft_print_road(t_data *d)
{
	t_node	*n;

	n = d->graph;
	while (n)
	{
		if (n->used)
			ft_print_node(n, *d);
		n = n->next;
	}
}

void		ft_options(t_data *d)
{
	if (d->opt.h)
		ft_print_options();
}
