#include "lem_in.h"
#include <fcntl.h>

void	ft_prepare_graph(t_data *d, t_node *n)
{
	t_link	*link;

	link = n->link;
	//printf("____%s\n", n->name);
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist) && 
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
	d->tabant = NULL;
}

void	ft_generate_ant(t_data *d)
{
	int 	i;

	i = 0;
	d->tabant = (t_ant*)ft_memalloc(sizeof(t_ant) * d->ant);
	while (i < d->ant)
	{
		d->tabant[i].id = i;
		d->tabant[i].node = d->n_start;
		i++;
	}
}

t_node	*ft_get_best_node(t_node *node, t_node *start, t_node *end)
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
				&& link->node->dist <= node->dist)
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

t_node	*ft_get_the_smallest(t_link *link)
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

t_node	*ft_get_start_node(t_node *node, t_node *end)
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

int 	ft_move(t_ant *ant, t_data d, int *space)
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

void	ft_start(t_data d)
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

int 	ft_count_link(t_node *n)
{
	t_link 	*l;
	int 	i;

	i = 0;
	l = n->link;
	while (l)
	{
		i++;
		l = l->next_l;
	}
	return (i);
}

t_node	*ft_utmost(t_node *n, t_node *origin)
{
	t_link 	*l;
	t_node 	*utmost;

	l = n->link;
	utmost = NULL;
	while (l)
	{
		if (ft_strcmp(origin->name, l->node->name) != 0 && 
			(utmost == NULL || l->node->dist < utmost->dist))
			utmost = l->node;
		l = l->next_l;
	}
	return (utmost);
}

t_link 	*ft_get_link(t_link *lst, t_node *n)
{
	t_link 	*l;

	l = lst;
	while (l)
	{
		if (ft_strcmp(l->node->name, n->name))
			return (l);
		l = l->next_l;
	}
	return (lst);
}

int  	ft_del_small(t_node *n, t_data *d)
{
	t_link 	*l;
	t_node	*best;

	l = n->link;
	best = NULL;
	//printf("%s : ", n->name);
	while (l)
	{
		if (ft_strcmp(l->node->name, d->n_start->name) != 0 &&
			ft_strcmp(l->node->name, d->n_end->name) != 0 && 
			(best == NULL || ft_utmost(l->node, n)->dist < best->dist))
		{
			best = ft_utmost(l->node, n);
			//printf("n %s ", n->name);
			//printf("l %s ", l->node->name);
			ft_del_link(&l->node->link, n->name);
			ft_del_link(&n->link, l->node->name);
			return (1);
		}
		l = l->next_l;
	}
	//printf("\n");
	return (0);
}

int 	ft_check_if_kill(t_node *n, t_data *d)
{
	int 	nb_link;
	t_link 	*l;

	nb_link = ft_count_link(n);
	l = n->link;
	if (nb_link >= 3)
	{
		//printf("%s \n", n->name);
		while (l)
		{
			if (ft_count_link(l->node) >= 3 && 
				ft_strcmp(l->node->name, d->n_start->name) != 0 &&
				ft_strcmp(l->node->name, d->n_end->name) != 0)
			{
				//printf("%s ", n->name);
				if (ft_del_small(n, d))
					return (1);
			}
			l = l->next_l;
		}
	}
	return (0);
}

void	ft_the_killer_link(t_data *d, t_node *n)
{
	t_link	*link;

	link = n->link;
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist) && 
			ft_strcmp(link->node->name, d->n_start->name) != 0 &&
			ft_strcmp(link->node->name, d->n_end->name) != 0)
		{
			if (ft_check_if_kill(link->node, d))
				ft_prepare_graph(d, d->n_end);
			else
				ft_the_killer_link(d, link->node);

		}
		link = link->next_l;
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

	//ft_print_data(d);
	ft_prepare_graph(&d, d.n_end);
	ft_the_killer_link(&d, d.n_end);
	//ft_print_data(d);

	ft_generate_ant(&d);
	//ft_print_ant(d.list_ant);
	//printf("__________START\n");
	ft_start(d);
	//ft_print_ant(d.tabant[0], 1);
	//if (d.n_end->nb_ant ! d.ant)
	//	ft_error();
	//ft_print_data(d);
	return (0);
}