#include "lem_in.h"

void	ft_print_node(t_node *n)
{
	t_link	*link;
	t_node	*child;

	link = n->link;
	child = NULL;
	ft_putstr(n->name);
	ft_putstr(" [dist: ");
	ft_putnbr(n->dist);
	ft_putchar(']');
	ft_putstr("[nb_ant: ");
	ft_putnbr(n->nb_ant);
	ft_putchar(']');
	//ft_putchar(' ');
	//ft_putnbr(n->x);
	//ft_putchar(' ');
	//ft_putnbr(n->y);

	if (link)
		ft_putstr(" -> ");
	while (link)
	{
		child = link->node;
		ft_putstr(child->name);
		ft_putstr(" [dist: ");
		ft_putnbr(child->dist);
		ft_putchar(']');
		ft_putstr("[nb_ant: ");
		ft_putnbr(child->nb_ant);
		ft_putchar(']');
		//ft_putchar(' ');
		//ft_putnbr(child->x);
		//ft_putchar(' ');
		//ft_putnbr(child->y);
		if (link->next_l)
			ft_putstr(", ");
		link = link->next_l;
	}
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
	ft_print_node(d.n_start);
	ft_putstr("\n[END] : ");
	ft_print_node(d.n_end);

	ft_putstr("\n[ROOMS]");
	while (g)
	{
		ft_putchar('\n');
		ft_print_node(g);
		g = g->next;
	}
}

void	ft_print_ant(t_ant ant, int space)
{
	if (space)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant.id);
	ft_putchar('-');
	ft_putstr(ant.node->name);
//	ft_putchar('\n');
}