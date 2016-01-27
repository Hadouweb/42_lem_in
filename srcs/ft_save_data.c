#include "lem_in.h"

t_lst	*ft_create_line(char *str)
{
	t_lst	*list;

	list = (t_lst*)ft_memalloc(sizeof(t_lst));
	list->str = ft_strdup(str);
	return (list);
}

void	ft_list_push_back(t_lst **l, char *str)
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