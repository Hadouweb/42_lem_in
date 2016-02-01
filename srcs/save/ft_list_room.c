#include "lem_in.h"

static t_node	*ft_create_node(char *str, int r)
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
	node->dist = 0;
	node->nb_ant = 0;
	node->link = NULL;
	node->used = 0;
	node->id = r;
	return (node);
}


static t_link	*ft_create_link(t_node *child)
{
	t_link	*link;

	link = (t_link*)ft_memalloc(sizeof(t_link));
	link->node = child;
	return (link);
}

void			ft_push_node(char *str, t_node **graph, int r)
{

	t_node	*n;

	n = *graph;
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = ft_create_node(str, r);
	}
	else
	{
		*graph = ft_create_node(str, r);
	}
}

void			ft_push_link(t_node *parent, t_node *child)
{
	t_link	*link;

	link = parent->link;
	if (link)
	{
		while (link->next_l)
			link = link->next_l;
		link->next_l = ft_create_link(child);
	}
	else
		parent->link = ft_create_link(child);
}

void 			ft_del_link(t_link **lst, char *link)
{
	t_link	*l;
	t_link	*tmp;
	int 	find;

	l = *lst;
	tmp = NULL;
	find = 1;
	if (ft_strcmp(l->node->name, link) == 0)
	{
		tmp = l;
		if (tmp->next_l)
			*lst = tmp->next_l;
	}
	else
	{
		while (l && find)
		{
			if (ft_strcmp(l->next_l->node->name, link) == 0)
			{
				tmp = l->next_l;
				if (tmp && tmp->next_l)
					l->next_l = tmp->next_l;
				else
					l->next_l = NULL;
			}
			l = l->next_l;
		}
	}
	free(tmp);
	tmp = NULL;
}