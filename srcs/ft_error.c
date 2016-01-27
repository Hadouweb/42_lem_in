#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
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

int 	ft_is_name(char *str, int i)
{
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	return (i);
}

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