/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:03:03 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/01 08:03:04 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst	*ft_create_line(char *str)
{
	t_lst	*list;

	list = (t_lst*)ft_memalloc(sizeof(t_lst));
	list->str = ft_strdup(str);
	return (list);
}

void			ft_list_push_back(t_lst **l, char *str)
{
	t_lst	*list;

	list = *l;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_line(str);
	}
	else
		*l = ft_create_line(str);
}
