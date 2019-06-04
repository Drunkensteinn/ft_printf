/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:54:25 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 18:54:39 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		kostil_5(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if ((g_flags & minus) && !(g_flags & plus) && !(g_flags & zero) &&
	(*symbol != '-') && (*str != '-') && !(g_flags & space))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_6(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if ((g_flags & space) && !(g_flags & plus) &&
	(g_flags & minus) && ((*tmp)->j))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes + 1], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_7(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if (!(g_flags & plus) && (g_flags & minus) && ((*tmp)->j) &&
	!(g_flags & space))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes + l2], str, (*tmp)->n - l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_8(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if ((g_flags & plus) && (g_flags & u || g_flags & U) &&
	!(g_flags & minus) && !((*tmp)->j) && !(g_flags & space))
	{
		*str += 1;
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

void			output(int fd, char *buff, size_t length)
{
	if (fd > 0)
		write(fd, &buff[0], length);
	if (fd == 0)
		write(1, &buff[0], length);
}
