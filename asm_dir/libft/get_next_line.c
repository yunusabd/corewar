/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:05:04 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/22 16:27:17 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_read_file(const int fd, char *str, int *end)
{
	int size;

	size = 0;
	if (!(size = read(fd, str, BUFF_SIZE)))
		*end = 1;
	if (size == -1)
		return (0);
	str[size] = '\0';
	return (str);
}

static char	*ft_store_line(const int fd, int *end, char *str)
{
	char	*new;
	char	*saved;
	int		j;

	j = 0;
	if (!(new = ft_strnew(BUFF_SIZE)) ||
	(!(str)[0] && !(str = ft_read_file(fd, str, end))))
		return (NULL);
	while ((str)[j] != '\n' && !*end)
	{
		j++;
		if (!str[j])
		{
			saved = str;
			new = ft_read_file(fd, new, end);
			if (!(str = ft_strjoin(str, new)))
				return (NULL);
			free(saved);
		}
	}
	ft_strdel(&new);
	return (str);
}

static int	del_ls(t_list **list, t_list **node, const int fd, int *end)
{
	t_list *prev;

	prev = NULL;
	*list = *node;
	while ((*list)->content_size != (size_t)fd)
	{
		if ((*list)->next && ((*list)->next->content_size == (size_t)fd))
			prev = *list;
		*list = (*list)->next;
	}
	if (*node != *list)
	{
		prev->next = (*list)->next;
		free((*list)->content);
		free(*list);
	}
	else
	{
		*node = (*node)->next;
		free((*list)->content);
		free(*list);
		*list = *node;
		return (*end) ? (0) : (1);
	}
	return (0);
}

int			gnl_solve(t_list **list, t_list **node, char **line, const int fd)
{
	int end;
	int i;

	end = 0;
	i = 0;
	if ((!((*list)->content) && (!((*list)->content = ft_strnew(BUFF_SIZE))))
		|| (!((*list)->content = ft_store_line(fd, &end, (*list)->content)))
		|| !(*line = ft_strnew(ft_strlen((*list)->content))))
		return (-1);
	if (end && !(((char *)((*list)->content))[0]))
		return (del_ls(list, node, fd, &end));
	while (((char *)((*list)->content))[i] != '\n'
	&& ((char *)((*list)->content))[i] != '\0')
		i++;
	*line = ft_strncpy(*line, (*list)->content, i);
	if (!(((char *)(*list)->content)[i]))
		((char *)((*list)->content))[0] = '\0';
	else
		(*list)->content = (char *)ft_memmove((*list)->content,
		((*list)->content) + i + 1, ft_strlen((*list)->content) - i);
	if (((*list) && !(((char *)((*list)->content))[0])) &&
		(del_ls(list, node, fd, &end)))
		return (1);
	*list = *node;
	return (2);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*node;

	node = list ? list : NULL;
	if (BUFF_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	while (list && list->content_size != (size_t)fd)
		list = list->next;
	if (!list)
	{
		if (!(list = (t_list *)malloc(sizeof(*list))))
			return (0);
		list->content = NULL;
		list->content_size = fd;
		list->next = NULL;
		if (node)
			ft_lstadd(&node, list);
		node = list;
	}
	return (gnl_solve(&list, &node, line, fd));
}
