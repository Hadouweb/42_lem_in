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
	ft_putstr("data : \n");
	ft_putstr("Ant : ");
	ft_putnbr(d.ant);
	ft_putstr("\nStart : ");
	ft_print_node(d.start);
}