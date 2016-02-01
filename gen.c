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
#include <fcntl.h>

void	ft_print_node(int size, int start, int end, int fd)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (i == start)
		{
			ft_putstr_fd("##start\n", fd);
			ft_putnbr_fd(i, fd);
		}
		else if (i == end)
		{
			ft_putstr_fd("##end\n", fd);
			ft_putnbr_fd(i, fd);
		}
		else
			ft_putnbr_fd(i, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(rand() % (10 * size), fd);
		write(fd, " ", 1);
		ft_putnbr_fd(rand() % (10 * size), fd);
		write(fd, "\n", 1);
		i++;
	}
}

void	ft_print_link(int size, int density, int fd)
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
				ft_putnbr_fd(i, fd);
				write(fd, "-", 1);
				ft_putnbr_fd(j, fd);
				write(fd, "\n", 1);
			}
			j++;
		}
		i++;
	}
}

void	ft_generate(int fd)
{
	int		size;
	int		density;
	int		nb_ant;
	int		start;
	int		end;


	size = 10;
	density = 10;
	nb_ant = 10;
	start = rand() % size;
	end = rand() % size;
	ft_putnbr_fd(nb_ant, fd);
	write(fd, "\n", 1);
	ft_print_node(size, start, end, fd);
	ft_print_link(size, density, fd);
}

int 	main(void)
{
	int 	fd;

	fd = 0;
	fd = open("test", O_TRUNC | O_CREAT | O_APPEND | O_WRONLY, 0660);
	ft_generate(fd);
	close(fd);
	return (0);
}
