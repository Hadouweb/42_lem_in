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
	d->list_ant = NULL;
}

t_ant	*ft_create_ant(int id, t_node *start)
{
	t_ant	*ant;

	ant = (t_ant*)ft_memalloc(sizeof(t_ant));
	ant->id = id;
	ant->node = start;
	return (ant);
}

void	ft_push_ant(int id, t_ant **ant, t_node *start)
{

	t_ant	*a;

	a = *ant;
	if (a)
	{
		while (a->next)
			a = a->next;
		a->next = ft_create_ant(id, start);
	}
	else
	{
		*ant = ft_create_ant(id, start);
	}
}

void	ft_generate_ant(t_data *d)
{
	int 	i;

	i = 0;
	while (i < d->ant)
	{
		ft_push_ant(i, &d->list_ant, d->n_start);
		i++;
	}
}

t_node	*ft_get_best_node(t_node *node, t_node *start, t_node *end)
{
	t_link	*link;
	t_node	*best;

	link = node->link;
	//printf("_____________\n");
	//ft_print_node(node);
	//printf("\n");
	best = NULL;
	if (node->link)
	{
		best = NULL;
		while (link && !best)
		{
		//	ft_print_node(link->node);
		//	printf("%d \n", link->node->nb_ant);
		//	printf("%s %s \n", link->node->name, start->name);
		//	printf("%d %d\n", link->node->dist, node->dist);
			if (link->node->nb_ant == 0 && ft_strcmp(link->node->name, start->name) != 0 && link->node->dist != 0 &&
				(ft_strcmp(node->name, start->name) == 0 || link->node->dist < node->dist))
				best = link->node;
			if (ft_strcmp(link->node->name, end->name) == 0) 
				return (link->node);
			link = link->next_l;
		}
		//ft_print_node(best);
		link = node->link;
		if (best)
		{
			while (link)
			{
			//	printf("ok\n");
				if (link->node->nb_ant == 0 && ft_strcmp(link->node->name, start->name) != 0 &&
					link->node->dist < best->dist && link->node->dist != 0)
					best = link->node;
				link = link->next_l;
			}
		}
		//ft_print_node(best);
	}
	return (best);
}

void	ft_start(t_data d)
{
	t_ant	*ant;
	t_node	*best_node;
	int 	i;

	ant = d.list_ant;
	best_node = NULL;
	i = 0;
	while (ant || d.n_end->nb_ant < d.ant)
	{
		best_node = ft_get_best_node(ant->node, d.n_start, d.n_end);
		//ft_print_node(ant->node);
		if (best_node)
		{
		//	ft_print_node(best_node);
			ant->node->nb_ant -= 1;
			best_node->nb_ant += 1;
			ant->node = best_node;
			ft_print_ant(ant);
		}
		ant = ant->next;
		if (!best_node)
		{
			ft_putstr("\n");
			ant = d.list_ant;
			if (i > 20)
				break;
		}
		i++;
	}
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
	ft_generate_ant(&d);
	//ft_print_ant(d.list_ant);
	printf("START\n");
	ft_start(d);
	ft_print_data(d);
	return (0);
}