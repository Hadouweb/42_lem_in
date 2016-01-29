#include "lem_in.h"

void	ft_error()
{
	ft_putstr("Error : ");
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
			ft_error();
		i++;
	}

	nbr = ft_atoi(str);
	if (!(nbr > 0 && nbr <= 2147483647))
		ft_error();
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