#include "lem_in.h"

void	ft_print_node(t_node *n)
{
	t_link	*link;
	t_node	*child;

	link = n->link;
	child = NULL;
	ft_putstr(n->name);
	ft_putchar(' ');
	ft_putnbr(n->x);
	ft_putchar(' ');
	ft_putnbr(n->y);

	while (link)
	{
		child = link->node;
		ft_putchar('\t');
		ft_putstr(child->name);
		ft_putchar(' ');
		ft_putnbr(child->x);
		ft_putchar(' ');
		ft_putnbr(child->y);
		link = link->next_l;
	}
}

void	ft_print_data(t_data d)
{
	t_node	*g;

	g = d.graph;
	ft_putstr("\n[DATA]\n");

	ft_putstr("[ANT] : ");
	ft_putnbr(d.ant);

	ft_putstr("\n[START] : ");
	ft_print_node(d.start);
	ft_putstr("\n[END] : ");
	ft_print_node(d.end);

	ft_putstr("\n[ROOMS]");
	while (g)
	{
		ft_putchar('\n');
		ft_print_node(g);
		g = g->next;
	}
}