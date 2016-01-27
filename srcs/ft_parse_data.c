#include "lem_in.h"

void	ft_push_node(char *str, t_node **graph)
{
	t_node	*n;

	n = *graph;
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = ft_create_node(str);
	}
	else
		*graph = ft_create_node(str);
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
		else if (ft_is_node(l))
			ft_push_node(l->str, &d.graph);
		l = l->next;
		i++;
	}
	ft_print_data(d);
}

int 	ft_is_cmd(char *str)
{
	int 	i;

	i = 0;
	while (str[i] && str[i] == '#')
		i++;
	return (i);
}

t_node	*ft_create_node(char *str)
{
	t_node	*node;
	int 	ret;

	ret = 0;
	node = (t_node*)ft_memalloc(sizeof(t_node));
	node->name = ft_strdup_limit(str, ' ');
	ret += ft_strlen_limit(&str[ret], ' ') + 1;
	node->x = ft_atoi(&str[ret]);
	ret += ft_strlen_limit(&str[ret], ' ') + 1;
	node->y = ft_atoi(&str[ret]);
	return (node);
}

void 	ft_special_cmd(t_lst *l, t_data *d)
{
	if (ft_strcmp(l->str, "##start") == 0)
	{
		if (!ft_is_node(l->next))
			ft_error();
		d->start = ft_create_node(l->next->str);
	}
	else if (ft_strcmp(l->str, "##end") == 0)
	{
		if (!ft_is_node(l->next))
			ft_error();
		d->end = ft_create_node(l->next->str);
	}
}