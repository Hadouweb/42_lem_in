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