/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_0_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:54:57 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 17:54:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		isflags_signed(va_list ap)
{
	if (g_flags & hh || g_flags & h)
		return ((g_flags & h) ? ((short)(va_arg(ap, int))) :
	(char)((va_arg(ap, int))));
	else if (g_flags & l || g_flags & ll)
		return ((g_flags & ll) ? ((va_arg(ap, long long))) :
	((va_arg(ap, long))));
	else if (g_flags & j)
		return (va_arg(ap, intmax_t));
	else if (g_flags & z)
		return (va_arg(ap, size_t));
	return (0);
}

uintmax_t		isflags_unsigned(va_list ap)
{
	if (g_flags & hh || g_flags & h)
		return ((g_flags & h) ? ((unsigned short)(va_arg(ap, int))) :
	((unsigned char)(va_arg(ap, int))));
	else if (g_flags & l || g_flags & ll)
		return ((g_flags & ll) ? ((va_arg(ap, unsigned long long))) :
	((va_arg(ap, unsigned long))));
	else if (g_flags & j)
		return (va_arg(ap, uintmax_t));
	else if (g_flags & z)
		return ((uintmax_t)va_arg(ap, size_t));
	return (0);
}

inline void		p_pointer_addres(t_alist **tmp, va_list ap)
{
	void		*p;

	p = (va_arg(ap, void *));
	(p) ? (ft_itoa_base_printfu((uintmax_t)p, 16, 0, tmp)) :
	(pointer_zero_f(tmp));
}

inline void		pointer_zero_f(t_alist **tmp)
{
	!(g_flags & presicions) ? (pointer_zero_f_1(tmp)) :
	(pointer_prec_zero(tmp));
}

inline void		pointer_zero_f_1(t_alist **tmp)
{
	char		s[(*tmp)->j];
	size_t		l;

	l = (*tmp)->j;
	s[(*tmp)->j] = '\0';
	if ((*tmp)->j && (g_flags & zero))
	{
		s[0] = '0';
		s[1] = 'x';
		ft_bchr(&s[2], '0', (*tmp)->j - 2);
		buffering(tmp, 0, l, s);
	}
	else if ((*tmp)->j && !(g_flags & zero))
	{
		buffering(tmp, 0, 3, "0x0");
		return ;
	}
	else
		buffering(tmp, 0, 3, "0x0");
}
