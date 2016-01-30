#include "lem_in.h"

void 	ft_special_cmd(t_lst *l, t_data *d)
{
	if (ft_strcmp(l->str, "##start") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error();
		d->start = l->next->str;
	}
	else if (ft_strcmp(l->str, "##end") == 0)
	{
		if (!ft_is_node(l->next->str))
			ft_error();
		d->end = l->next->str;
	}
}