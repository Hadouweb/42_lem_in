/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 07:29:18 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 07:29:21 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_init_data(t_data *d)
{
	d->ant = 0;
	d->graph = NULL;
	d->start = NULL;
	d->end = NULL;
	d->n_start = NULL;
	d->n_end = NULL;
	d->tabant = NULL;
	d->step = 0;
	d->tmp_ant = NULL;
	d->opt.h = 0;
	d->opt.e = 0;
	d->opt.r = 0;
	d->opt.o = 0;
	d->opt.s = 0;
	d->opt.g = 0;
	d->opt.a = 0;
	d->opt.l = 0;
}

static void	ft_check_after_parse(t_data *d)
{
	if (!d->start || !d->end)
		ft_error("Start or end is missing", *d);
	ft_verif_double_name(d);
	ft_get_start_end(d);
	if (d->opt.o)
		ft_make_graph_fast(d->n_end);
	else
		ft_make_graph(d->n_end);
}

static void	ft_load(t_data *d, t_lst **lst)
{
	char	*line;
	int		i;

	i = 0;
	if (d->opt.h)
		ft_print_options();
	if (d->opt.g)
		ft_use_map(lst);
	else
	{
		while (get_next_line(0, &line) > 0)
		{
			ft_list_push_back(lst, line);
			ft_strdel(&line);
			i++;
		}
	}
	if (!d->opt.o)
		ft_verif_double(*lst, *d);
	ft_parse_data(lst, d);
	ft_check_after_parse(d);
}

static void	ft_load_options(t_data d)
{
	if (d.opt.r)
		ft_print_road(&d);
	if (d.opt.s)
	{
		ft_putstr("\033[0;102m \033[1;30mSTEPS : ");
		ft_putnbr(d.step);
		ft_putstr(" \033[0m\n");
	}
	if (d.n_end->nb_ant != d.ant)
		ft_error("No valid path", d);
}

int			main(int ac, char **av)
{
	t_lst	*lst;
	t_data	d;
	int		i;

	lst = NULL;
	ft_init_data(&d);
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (d.opt.a)
			{
				d.tmp_ant = ft_strdup(av[i++]);
				d.opt.a = 0;
			}
			else
				ft_parse_options(av[i++], &d);
		}
	}
	ft_load(&d, &lst);
	ft_generate_ant(&d);
	ft_start(&d);
	ft_load_options(d);
	return (0);
}
