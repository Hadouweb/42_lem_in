#include "lem_in.h"

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
	ft_print_data(*d);
}
