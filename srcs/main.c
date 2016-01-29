#include "lem_in.h"
#include <fcntl.h>

void	ft_init_data(t_data *d)
{
	d->ant = 0;
	d->graph = NULL;
	d->start = NULL;
	d->end = NULL;
}

int		main(int ac, char **av)
{
	char	*line;
	t_lst	*lst;
	int		fd;
	t_data	d;

	lst = NULL;
	ac = 1;
	fd = open(av[1], O_RDONLY);
	ft_init_data(&d);
	while (get_next_line(fd, &line) > 0)
	{
		ft_list_push_back(&lst, line);
		ft_strdel(&line);
	}
	ft_parse_data(&lst, &d);
	sleep(5);
	return (0);
}