#include "lem_in.h"

static int  ft_del_small(t_node *n, t_data *d)
{
	t_link 	*l;
	t_node	*best;

	l = n->link;
	best = NULL;
	while (l)
	{
		if (ft_strcmp(l->node->name, d->n_start->name) != 0 &&
			ft_strcmp(l->node->name, d->n_end->name) != 0 && 
			(best == NULL || ft_utmost(l->node, n)->dist < best->dist))
		{
			best = ft_utmost(l->node, n);
			ft_del_link(&l->node->link, n->name);
			ft_del_link(&n->link, l->node->name);
			return (1);
		}
		l = l->next_l;
	}
	return (0);
}

static int 	ft_check_if_kill(t_node *n, t_data *d)
{
	int 	nb_link;
	t_link 	*l;

	nb_link = ft_count_link(n);
	l = n->link;
	if (nb_link >= 3)
	{
		while (l)
		{
			if (ft_count_link(l->node) >= 3 && 
				ft_strcmp(l->node->name, d->n_start->name) != 0 &&
				ft_strcmp(l->node->name, d->n_end->name) != 0)
			{
				if (ft_del_small(n, d))
					return (1);
			}
			l = l->next_l;
		}
	}
	return (0);
}

void		ft_make_graph(t_data *d, t_node *n)
{
	t_link	*link;

	link = n->link;;
	while (link)
	{
		if ((link->node->dist == 0 || link->node->dist > n->dist) && 
			ft_strcmp(link->node->name, d->n_start->name) &&
			ft_strcmp(link->node->name, d->n_end->name))
		{
			link->node->dist = n->dist + 1;
			ft_make_graph(d, link->node);
		}
		link = link->next_l;
	}
}

void		ft_the_killer_link(t_data *d, t_node *n)
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
				ft_make_graph(d, d->n_end);
			else
				ft_the_killer_link(d, link->node);

		}
		link = link->next_l;
	}
}
