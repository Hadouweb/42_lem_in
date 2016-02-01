/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:01:46 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:01:48 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>
#include <time.h>

void	ft_fprint_node(int size, int start, int end, int fd)
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

void	ft_fprint_link(int size, int density, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (density > rand() % 100)
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

	srand(time(NULL));
	size = rand() % 2000;
	density = rand() % 5;
	nb_ant = rand() % 10000 + 100;
	start = rand() % size;
	end = rand() % size;
	ft_putnbr_fd(nb_ant, fd);
	write(fd, "\n", 1);
	ft_fprint_node(size, start, end, fd);
	ft_fprint_link(size, density, fd);
}

int		ft_use_map(t_lst **lst)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("test", O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0660);
	ft_generate(fd);
	close(fd);
	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_list_push_back(lst, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
