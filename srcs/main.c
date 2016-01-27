#include "lem_in.h"


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