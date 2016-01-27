#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	ft_print_data(t_data d)
{
	ft_putstr("data : \n");
	ft_putstr("Ant : ");
	ft_putnbr(d.ant);
}

void 	ft_is_ant(char *str, t_data *d)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		else
			d->ant = ft_atoi(str);
		i++;
	}
}

int 	ft_is_cmd(char *str)
{
	int 	i;

	i = 0;
	while (str[i] && str[i] == '#')
		i++;
	return (i);
}

int 	ft_is_name(char *str, int i)
{
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	return (i );
}

int 	ft_is_number(char *str, int i)
{
	int 	s;

	s = 0;
	while (str[i++] == ' ')
		s++;
	if (s != 1)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i - 1);
}

int 	ft_is_node(t_lst *l)
{
	int 	i;
	int 	s;
	int 	j;
	int 	ret;

	i = 0;
	j = 2;
	s = 0;
	ret = 0;
	if (l && l->str)
	{
		if ((ret = ft_is_name(l->str, i)) == 0)
			return (0);
		i += ret;
		if ((ret = ft_is_number(l->str, i)) == 0)
			return (0);
		i += ret;
		if ((ret = ft_is_number(l->str, i)) == 0)
			return (0);
		i += ret;
		if (l->str[i])
			return (0);
	}
	else
		return (0);
	return (1);
}

void 	ft_special_cmd(t_lst *l, t_data *d)
{
	if (ft_strcmp(l->str, "##start") == 0)
	{
		if (!ft_is_node(l->next))
			ft_error();
		d->start = NULL;
	}
}

void	ft_parse_data(t_lst *l)
{
	int 	i;
	int 	cmd;
	t_data	d;

	i = 0;
	cmd = 0;
	while (l)
	{
		printf("%s [%d]\n", l->str, i);

		if (i == 0)
			ft_is_ant(l->str, &d);
		else if (ft_is_cmd(l->str) == 2)
			ft_special_cmd(l, &d);
		l = l->next;
		i++;
	}
	ft_print_data(d);
}

int		main(void)
{
	char	*line;
	t_lst	*lst;

	lst = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
	}
	ft_parse_data(lst);
	return (0);
}