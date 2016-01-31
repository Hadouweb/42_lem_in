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
}

int			main(int ac, char **av)
{
	char	*line;
	t_lst	*lst;
	int		fd;
	t_data	d;
	int 	i;

	lst = NULL;
	ac = 1;
	fd = open(av[1], O_RDONLY);
	ft_init_data(&d);
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
		i++;
	}
	//ft_verif_double(lst);
	ft_parse_data(&lst, &d);

	//ft_print_data(d);
	if (i > 50000)
		ft_make_graph_fast(d.n_end);
	else
		ft_make_graph(d.n_end);
	//ft_the_killer_link(&d, d.n_end);


	ft_generate_ant(&d);
	//ft_print_ant(d.list_ant);
	//printf("__________START\n");
	ft_start(d);
	//ft_print_ant(d.tabant[0], 1);
	//ft_print_data(d);
	if (d.n_end->nb_ant != d.ant)
		ft_error();
	return (0);
}