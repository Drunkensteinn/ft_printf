/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_0_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 23:12:23 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/26 23:12:24 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int				width_c_zero(t_alist **tmp)
{
	char				s[(*tmp)->j];

	s[(*tmp)->j] = '\0';
	if ((*tmp)->j > 1 && (g_flags & zero))
	{
		ft_bchr(&s[0], '0', (*tmp)->j - 1);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], s, (*tmp)->j - 1);
		(*tmp)->size_bytes += (*tmp)->j;
		output((*tmp)->fd, (*tmp)->buff, (*tmp)->j + 1);
		ft_bzero((*tmp)->buff, BUFF_SIZE);
		ft_memcpy(s, (*tmp)->str, (ft_strchr((*tmp)->str, '%')) ?
		((*tmp)->extra =
		(ft_strchr((*tmp)->str, '%') - (*tmp)->str)) :
		((*tmp)->extra = ft_strlen((*tmp)->str)));
		output((*tmp)->fd, s, (*tmp)->extra);
		(*tmp)->size_bytes += (*tmp)->extra;
		(*tmp)->str += (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int				width_c_eof(t_alist **tmp)
{
	char				s[(*tmp)->j];

	s[(*tmp)->j] = '\0';
	if ((*tmp)->j > 1 && !(g_flags & zero))
	{
		(*tmp)->j -= 1;
		ft_bchr(&s[0], ' ', (*tmp)->j);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], s, (*tmp)->j);
		(*tmp)->size_bytes += (*tmp)->j;
		output((*tmp)->fd, (*tmp)->buff, (*tmp)->size_bytes + 1);
		(*tmp)->size_bytes += 1;
		ft_bzero((*tmp)->buff, BUFF_SIZE);
		ft_memcpy(s, (*tmp)->str, (ft_strchr((*tmp)->str, '%')) ?
		((*tmp)->extra =
		(ft_strchr((*tmp)->str, '%') - (*tmp)->str)) :
		((*tmp)->extra = ft_strlen((*tmp)->str)));
		output((*tmp)->fd, s, (*tmp)->extra);
		(*tmp)->size_bytes += (*tmp)->extra;
		(*tmp)->str += (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline void				p_b_f(t_alist **tmp, int step, size_t size)
{
	char				s[(*tmp)->j];

	s[(*tmp)->j] = '\0';
	if (g_flags & presicions && (*tmp)->k == 0 && (*tmp)->j)
	{
		ft_bchr(s, '0', (*tmp)->j);
		buffering(tmp, 0, (*tmp)->j, s);
		return ;
	}
	buffering(tmp, step, size, "(null)\0");
}

inline void				s_string(t_alist **tmp, va_list ap)
{
	char				*f;

	if (search() == l)
		unicode_s(tmp, ap);
	else
	{
		f = va_arg(ap, char *);
		(!f) ? (p_b_f(tmp, 0, 6)) : (s_s_precision(tmp, ft_strlen(f), f));
		g_flags ^= s;
	}
}

inline void				k_time_date(t_alist **tmp, va_list ap)
{
	time_t				timer;

	timer = PLS_PASS;
	(va_arg(ap, int) == 1) ? (buffering(tmp, 1, 24, ctime(&timer))) :
	(buffering(tmp, 1, 1, "0"));
	g_flags ^= k;
}
