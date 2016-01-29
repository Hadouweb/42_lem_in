#include "lem_in.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	t_lst	*lst;
	int		fd;

	lst = NULL;
	ac = 1;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
	}
	ft_parse_data(lst);
	return (0);
}