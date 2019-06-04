/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:09:22 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 19:09:35 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		pre_output1(t_alist **tmp, size_t *size)
{
	if ((*tmp)->size_bytes == BUFF_SIZE)
	{
		output((*tmp)->fd, (*tmp)->buff, (*tmp)->size_bytes);
		ft_bzero((*tmp)->buff, BUFF_SIZE);
		(*tmp)->i = 0;
	}
	else if (*(*tmp)->str == '%')
	{
		if (pre_output1_1(tmp))
		{
			(*tmp)->str += 1;
			return (1);
		}
	}
	else if (pre_output3(tmp, size))
		return (1);
	return (0);
}

inline int		pre_output1_1(t_alist **tmp)
{
	char s[(*tmp)->j];

	if ((*tmp)->j && !(g_flags & minus) && !(g_flags & zero))
	{
		ft_bchr(s, ' ', (*tmp)->j);
		s[(*tmp)->j - 1] = '%';
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], s, (*tmp)->j);
		(*tmp)->size_bytes += (*tmp)->j;
		(*tmp)->j = 0;
		return (1);
	}
	else if (!(*tmp)->j && *(*tmp)->str == '%')
	{
		ft_bchr((const void *)&(*tmp)->buff[(*tmp)->size_bytes], '%', 1);
		(*tmp)->size_bytes++;
		return (1);
	}
	return (preoutput_1_2(tmp));
}

inline int		preoutput_1_2(t_alist **tmp)
{
	char s[(*tmp)->j];

	if ((g_flags & zero) && ((*tmp)->j != 0) && !(g_flags & minus))
	{
		ft_bchr(s, '0', (*tmp)->j);
		s[(*tmp)->j - 1] = '%';
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], s, (*tmp)->j);
		(*tmp)->size_bytes += (*tmp)->j;
		(*tmp)->j = 0;
		return (1);
	}
	else if (((*tmp)->j) && (g_flags & minus))
	{
		s[0] = '%';
		ft_bchr(&s[1], ' ', (*tmp)->j - 1);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], s, (*tmp)->j);
		(*tmp)->size_bytes += (*tmp)->j;
		(*tmp)->j = 0;
	}
	return (0);
}

inline int		pre_output3(t_alist **tmp, size_t *size)
{
	if ((*tmp)->j && !(g_flags & minus))
	{
		(*tmp)->size_bytes = BUFF_LEN;
		ft_bchr((const void *)&(*tmp)->buff[(*tmp)->size_bytes],
		' ', (*tmp)->size_bytes = (*tmp)->j);
		(*tmp)->size_bytes = BUFF_LEN;
		(*tmp)->j = 0;
		*size = 0;
		return (1);
	}
	return (0);
}
