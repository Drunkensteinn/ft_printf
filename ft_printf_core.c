/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:21:53 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/27 22:36:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_processing_1(va_list ap, t_alist **tmp)
{
	if (g_flags & d || g_flags & i)
	{
		d_i(tmp, ap);
		(g_flags & d) ? (g_flags ^= d) : (g_flags ^= i);
		return (1);
	}
	else if (g_flags & D)
	{
		ft_itoa_base_printf_s(va_arg(ap, long int), 10, 0, tmp);
		g_flags ^= D;
		return (1);
	}
	else if (g_flags & u)
	{
		u_u(tmp, ap);
		(g_flags & u) ? (g_flags ^= u) : (0);
		return (1);
	}
	else if (g_flags & U)
	{
		ft_itoa_base_printfu(va_arg(ap, unsigned long int), 10, 0, tmp);
		g_flags ^= U;
		return (1);
	}
	return (0);
}

int					ft_printf_processing_2(va_list ap, t_alist **tmp)
{
	if (g_flags & o)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		o_t(tmp, ap);
		g_flags ^= o;
		return (1);
	}
	else if (g_flags & O)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		ft_itoa_base_printfu(va_arg(ap, unsigned long int), 8, 0, tmp);
		g_flags ^= O;
		return (1);
	}
	else if (g_flags & x)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		x_hex(tmp, ap);
		g_flags ^= x;
		return (1);
	}
	return (0);
}

int					ft_printf_processing_3(va_list ap, t_alist **tmp)
{
	if (g_flags & X)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		(isflag()) ? (ft_itoa_base_printfu(isflags_unsigned(ap), 16, 1, tmp)) :
		(ft_itoa_base_printfu(va_arg(ap, unsigned int), 16, 1, tmp));
		g_flags ^= X;
		return (1);
	}
	else if (g_flags & b)
	{
		b_binary(tmp, ap);
		g_flags ^= b;
		return (1);
	}
	else if (g_flags & B)
	{
		ft_itoa_base_printfu(va_arg(ap, unsigned long int), 2, 0, tmp);
		g_flags ^= B;
		return (1);
	}
	return (0);
}

int					ft_printf_processing_4(va_list ap, t_alist **tmp)
{
	if (g_flags & p)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		p_pointer_addres(tmp, ap);
		g_flags ^= p;
		return (1);
	}
	else if (g_flags & c)
	{
		c_character(tmp, ap);
		g_flags ^= c;
		return (1);
	}
	else if (g_flags & C)
	{
		unicode_c(tmp, ap);
		g_flags ^= C;
		return (1);
	}
	return (0);
}

int					ft_printf_processing_5(va_list ap, t_alist **tmp)
{
	if (g_flags & s)
	{
		if (g_flags & plus)
			g_flags ^= plus;
		s_string(tmp, ap);
		g_flags ^= s;
		return (1);
	}
	else if (g_flags & S)
	{
		unicode_s(tmp, ap);
		g_flags ^= s;
		g_flags ^= l;
		g_flags ^= S;
		return (1);
	}
	else if (g_flags & k)
	{
		k_time_date(tmp, ap);
		g_flags ^= k;
		return (1);
	}
	return (0);
}
