/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:01:29 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 19:01:42 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			unicode_s(t_alist **tmp, va_list ap)
{
	wchar_t			*s_t;
	int				*s;

	if (!(s_t = va_arg(ap, wchar_t *)))
	{
		buffering(tmp, 0, 6, "(null)");
		return ;
	}
	s = unicode_len(s_t);
	unicode_s_1((size_t)s[0], s[1], s_t, tmp);
}

inline void			unicode_s_1(size_t size, int step,
					wchar_t *s_t, t_alist **tmp)
{
	unsigned int	value;
	char			*arr;

	(*tmp)->extra2 = 0;
	arr = (char *)malloc(sizeof(char) * step + 1);
	(*tmp)->tmp_1 = (char *)malloc(sizeof(char) * size + 1);
	while (*s_t)
	{
		value = (unsigned int)*s_t;
		(value <= 0x80) ? (unicode_0(tmp, value, arr, &step)) : (0);
		(value > 0x80 && value <= 0x800) ?
		(unicode_1(tmp, value, arr, &step)) : (0);
		(value > 0x800 && value <= 0x8000) ?
		(unicode_2(tmp, value, arr, &step)) : (0);
		(value > 0x8000) ? (unicode_3(tmp, value, arr, &step)) : (0);
		ft_memcpy(&(*tmp)->tmp_1[(*tmp)->extra2], arr, (size_t)step);
		(*tmp)->extra2 += step;
		s_t++;
	}
	(*tmp)->extra2 = 0;
	if (presicions_s(tmp, size, step))
		return ;
	buffering(tmp, 0, size, (*tmp)->tmp_1);
	ft_memdel((void *)&(*tmp)->tmp_1);
	ft_memdel((void *)&arr);
}

inline int			presicions_s(t_alist **tmp, size_t size, int step)
{
	char			s[size];

	s[size] = '\0';
	if (g_flags & presicions && (*tmp)->k != 0)
	{
		if ((*tmp)->k + (size_t)step <= size)
		{
			if ((*tmp)->k % step)
				(*tmp)->k = (size_t)step;
			ft_memcpy(s, (*tmp)->tmp_1, (*tmp)->k);
			s[(*tmp)->k] = '\0';
			g_flags ^= presicions;
			buffering(tmp, 0, (*tmp)->k, s);
			return (1);
		}
	}
	else if ((g_flags & presicions) && (*tmp)->k == 0 && !(g_flags & zero))
	{
		buffering(tmp, 0, 0, "");
		return (1);
	}
	else if (presicions_s_zero(tmp, s, size))
		return (1);
	return (0);
}

inline int			presicions_s_zero(t_alist **tmp, char *s, size_t len)
{
	len = 0;
	if ((g_flags & presicions) && (*tmp)->k == 0 &&
	(*tmp)->j != 0 && (g_flags & zero))
	{
		ft_bchr(s, '0', (*tmp)->j);
		buffering(tmp, 0, (*tmp)->j, s);
		return (1);
	}
	return (0);
}

inline void			make_us_whole_reference_to_dead_space(t_alist **tmp,
					int size, char *arr, char *arr_uni)
{
	if (arr == NULL)
	{
		buffering(tmp, 0, (size_t)size, arr_uni);
		return ;
	}
	ft_memcpy(arr, arr_uni, (size_t)size);
}
