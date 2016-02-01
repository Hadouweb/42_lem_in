#include "lem_in.h"

void	ft_error(char *str, t_data d)
{
	if (d.opt.e)
	{
		ft_putstr("Error: ");
		ft_putstr(str);
		write(1, "\n", 1);
	}
	else
		ft_putstr("Error\n");
	exit(1);
}

void 	ft_is_ant(char *str, t_data *d)
{
	int 		i;
	long long	nbr;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("The number of ants is invalid", *d);
		i++;
	}

	nbr = ft_atoi(str);
	if (!(nbr > 0 && nbr <= 2147483647))
		ft_error("The number of ants is invalid", *d);
	else
		d->ant = nbr;
}

int 	ft_is_cmd(char *str)
{
	int 	i;

	i = 0;
	while (str[i] && str[i] == '#')
		i++;
	return (i);
}

void	ft_verif_double(t_lst *lst, t_data d)
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
			ft_error("Duplicate items", d);
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
			ft_error("Duplicate rooms", *d);
		l = l->next;
	}
}