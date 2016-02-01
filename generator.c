/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 01:40:36 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 01:40:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_node(int size, int start, int end)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (i == start)
		{
			ft_putstr("##start\n");
			ft_putnbr(i);
		}
		else if (i == end)
		{
			ft_putstr("##end\n");
			ft_putnbr(i);
		}
		else
			ft_putnbr(i);
		write(1, " ", 1);
		ft_putnbr(rand() % (10 * size));
		write(1, " ", 1);
		ft_putnbr(rand() % (10 * size));
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_link(int size, int density)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (density > rand() % 50)
			{
				ft_putnbr(i);
				write(1, "-", 1);
				ft_putnbr(j);
				write(1, "\n", 1);
			}
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int		size;
	int		density;
	int		nb_ant;
	int		start;
	int		end;

	if (ac != 4)
	{
		ft_putstr("usage : size(rooms) density(percent) nb_of_ant");
		exit(0);
	}
	else
	{
		size = ft_atoi(av[1]);
		density = ft_atoi(av[2]);
		nb_ant = ft_atoi(av[3]);
		start = rand() % size;
		end = rand() % size;
		ft_putnbr(nb_ant);
		write(1, "\n", 1);
		ft_print_node(size, start, end);
		ft_print_link(size, density);
	}
	return (0);
}
