/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:01:26 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:02:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	ft_is_number(char *str, int i)
{
	int 	s;
	int 	ret;

	s = 0;
	ret = 0;
	if (str[i] != ' ')
		return (0);
	i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
		ret++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
		ret++;
	}
	if (ret)
		ret++;
	return (ret);
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
