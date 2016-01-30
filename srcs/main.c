#include "lem_in.h"
#include <fcntl.h>

void	ft_prepare_graph(t_data *d, t_node *n)
{
	t_link	*link;

	link = n->link;
	printf("____%s\n", n->name);
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist + 1) && 
			ft_strcmp(link->node->name, d->n_start->name) &&
			ft_strcmp(link->node->name, d->n_end->name))
		{
			link->node->dist = n->dist + 1;
			ft_prepare_graph(d, link->node);
		}
		link = link->next_l;
	}
}

void	ft_init_data(t_data *d)
{
	d->ant = 0;
	d->graph = NULL;
	d->start = NULL;
	d->end = NULL;
	d->n_start = NULL;
	d->n_end = NULL;
}

int		main(int ac, char **av)
{
	char	*line;
	t_lst	*lst;
	int		fd;
	t_data	d;

	lst = NULL;
	ac = 1;
	fd = open(av[1], O_RDONLY);
	ft_init_data(&d);
	while (get_next_line(0, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
	}
	ft_verif_double(lst);
	ft_parse_data(&lst, &d);
	ft_prepare_graph(&d, d.n_end);
	ft_print_data(d);
	return (0);
}