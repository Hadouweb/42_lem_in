#include "lem_in.h"
#include <fcntl.h>	

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
}

void 		ft_print_options(void)
{
	ft_putstr("usage: lem-in [-herosg]\n\n");
	ft_putstr("\th : print this message help\n");
	ft_putstr("\te : print error message\n");
	ft_putstr("\tr : print all rooms used\n");
	ft_putstr("\to : print the solution quickly\n");
	ft_putstr("\ts : print the number of steps\n");
	ft_putstr("\tg : print the solution with random map (1-500 rooms, 1-1000 ants)\n");
	ft_putstr("\ta : force the number of ant : -a number\n");
	ft_putchar('\n');
	exit(1);
}

void		ft_parse_options(char *options, t_data *d)
{
	int 	i;

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
			if (options[i] == 'h')
				d->opt.h = 1;
			else if (options[i] == 'e')
				d->opt.e = 1;
			else if (options[i] == 'r')
				d->opt.r = 1;
			else if (options[i] == 'o')
				d->opt.o = 1;
			else if (options[i] == 's')
				d->opt.s = 1;
			else if (options[i] == 'g')
				d->opt.g = 1;
			else if (options[i] == 'a')
				d->opt.a = 1;
			else
			{
				ft_putstr("lem-in: illegal option\n");
				ft_print_options();
			}
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
			ft_print_node(n);
		n = n->next;
	}
}

void		ft_options(t_data *d)
{
	if (d->opt.h )
		ft_print_options();
	if (d->opt.g)
		printf("Pouet\n");
}

int			main(int ac, char **av)
{
	char	*line;
	t_lst	*lst;
	int		fd;
	t_data	d;
	int 	i;

	lst = NULL;
	i = 1;
	fd = open(av[1], O_RDONLY);
	ft_init_data(&d);
	if (ac > 1)
	{
		while (i < ac)
		{
			if (d.opt.a)
			{
				d.tmp_ant = ft_strdup(av[i]);
				d.opt.a = 0;
			}
			else
				ft_parse_options(av[i], &d);
			i++;
		}
		ft_options(&d);
	}
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
		i++;
	}
	if (!d.opt.o)
		ft_verif_double(lst, d);
	ft_parse_data(&lst, &d);
	if (d.opt.o)
		ft_make_graph_fast(d.n_end);
	else
		ft_make_graph(d.n_end);
	ft_generate_ant(&d);
	ft_start(&d);
	if (d.opt.r)
		ft_print_road(&d);
	if (d.opt.s)
		printf("\n\e[0;102m \e[1;30mSTEPS : %d \e[0m\n", d.step);
	if (d.n_end->nb_ant != d.ant)
		ft_error("No valid path", d);
	return (0);
}