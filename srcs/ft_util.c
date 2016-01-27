#include "lem_in.h"

void	ft_print_node(t_node *n)
{
	ft_putstr(n->name);
	ft_putchar(' ');
	ft_putnbr(n->x);
	ft_putchar(' ');
	ft_putnbr(n->y);
}

void	ft_print_data(t_data d)
{
	t_node	*g;

	g = d.graph;
	ft_putstr("data : \n");
	ft_putstr("Ant : ");
	ft_putnbr(d.ant);
	ft_putstr("\nStart : ");
	ft_print_node(d.start);
	ft_putstr("\nEnd : ");
	ft_print_node(d.end);
	while (g)
	{
		ft_putchar('\n');
		ft_print_node(g);
		g = g->next;
	}
}