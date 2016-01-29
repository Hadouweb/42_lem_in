#include "lem_in.h"

void	ft_verif_double(t_lst *lst)
{
	t_lst	*l;
	t_lst	*r;
	int 	i;

	l = lst;
	while (l)
	{
		r = lst;
		i = 0;
		while (r)
		{
			if (ft_strcmp(l->str, r->str) == 0 && (l->str[0] != '#' || ft_is_cmd(l->str) == 2))
				i++;
			r = r->next;
		}
		if (i > 1)
			ft_error();
		l = l->next;
	}
}

void	ft_verif_double_name(t_data *d)
{
	t_node	*l;
	t_node	*r;
	int 	i;

	l = d->graph;
	while (l)
	{
		r = d->graph;
		i = 0;
		while (r)
		{
			if (ft_strcmp(l->name, r->name) == 0)
				i++;
			r = r->next;
		}
		if (i > 1)
			ft_error();
		l = l->next;
	}
}

void	ft_parse_data(t_lst **l, t_data *d)
{
	int 	i;
	int 	cmd;
	t_lst	*lst;
	int 	m;

	i = 0;
	cmd = 0;
	lst = *l;
	m = 0;
	while (lst)
	{
		printf("%s [%d]\n", lst->str, i);

		if (i == 0)
			ft_is_ant(lst->str, d);
		else if (ft_is_cmd(lst->str) == 2)
			ft_special_cmd(lst, d);
		else if (ft_is_node(lst->str) && m == 0)
			ft_push_node(lst->str, &d->graph);
		else if (ft_is_link(lst->str, d->graph) && ++m)
			;
		else if (ft_is_cmd(lst->str) > 0)
			;
		else
			ft_error();
		lst = lst->next;
		i++;
	}
	ft_verif_double_name(d);
	ft_print_data(*d);
}
