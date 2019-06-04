/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 21:09:38 by ablizniu          #+#    #+#             */
/*   Updated: 2018/01/28 21:09:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*semi_initialize(t_list *tmp, int fd)
{
	tmp->next = (t_list *)malloc(sizeof(t_list));
	tmp = tmp->next;
	tmp->content_size = (size_t)fd;
	tmp->content = NULL;
	tmp->next = NULL;
	return (tmp);
}

static t_list		*initialize(t_list **gnl, int fd)
{
	t_list			*tmp;

	if ((*gnl) == NULL || (*gnl)->content_size == (size_t)fd)
	{
		if ((*gnl) != NULL && (char *)(*gnl)->content)
			return ((*gnl));
		(*gnl) = (t_list *)malloc(sizeof(t_list));
		(*gnl)->content_size = (size_t)fd;
		(*gnl)->content = NULL;
		(*gnl)->next = NULL;
		return ((*gnl));
	}
	tmp = (*gnl);
	while (tmp->content_size != (size_t)fd)
	{
		if (!tmp->next)
		{
			tmp = semi_initialize(tmp, fd);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

static int			format(char **line, t_list **gnl, ssize_t f_read)
{
	char			*tmp;

	tmp = NULL;
	if (f_read == 0)
	{
		if (f_read == 0 && (*gnl)->content)
		{
			if (f_read == 0 && !*(char *)(*gnl)->content)
				return (0);
			*line = ft_strsub((*gnl)->content, 0, ft_strlen((*gnl)->content));
			ft_memdel((void *)&(*gnl)->content);
			return (1);
		}
		return (0);
	}
	*line = ft_strsub((*gnl)->content, 0, ft_strchr((*gnl)->content, '\n')
	? ft_strchr((*gnl)->content, '\n') - (char *)(*gnl)->content :
	ft_strlen((*gnl)->content));
	tmp = ft_strsub((ft_strchr((*gnl)->content, '\n') + 1), 0,
	ft_strlen(ft_strchr((*gnl)->content, '\n') + 1));
	ft_memdel(&(*gnl)->content);
	(*gnl)->content = ft_strsub(tmp, 0, ft_strlen(tmp));
	ft_strdel(&tmp);
	return (1);
}

static int			remainder_list(char **line, t_list **gnl)
{
	char			*tmp;

	tmp = NULL;
	if (!((*gnl)->content) || !*(char *)(*gnl)->content)
		return (0);
	if (ft_strchr((*gnl)->content, '\n'))
	{
		*line = ft_strsub((*gnl)->content, 0, ft_strchr((*gnl)->content, '\n') ?
		ft_strchr((*gnl)->content, '\n') - (char *)(*gnl)->content :
		ft_strlen((*gnl)->content));
		tmp = ft_strsub(ft_strchr((*gnl)->content, '\n') + 1, 0,
		ft_strlen(ft_strchr((*gnl)->content, '\n') + 1));
		ft_memdel(&(*gnl)->content);
		(*gnl)->content = ft_strsub(tmp, 0, ft_strlen(tmp));
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*tmp;
	t_list			*gnl;
	ssize_t			f_read;
	char			buff[BUFF_SIZE + 1];

	if (BUFF_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	gnl = initialize(&head, fd);
	ft_bzero(buff, BUFF_SIZE);
	if (gnl && (char *)gnl->content)
		if (remainder_list(line, &gnl))
			return (1);
	while ((f_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[f_read] = '\0';
		tmp = ft_strdup(gnl->content);
		ft_memdel((void *)&gnl->content);
		gnl->content = ft_strjoin(tmp, buff);
		ft_memdel((void *)&tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (format(line, &gnl, f_read));
}
