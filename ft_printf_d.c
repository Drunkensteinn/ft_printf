/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 22:24:43 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/21 19:40:07 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			fill_bits(t_alist **tmp, va_list ap)
{
	int				ret;

	ret = 0;
	fill_bits_1(tmp, &ret);
	fill_bits_2(tmp, &ret);
	fill_bits_3(tmp, &ret);
	fill_bits_4(tmp, &ret);
	if (*(*tmp)->str == 'k')
	{
		g_flags |= k;
		ret += 1;
	}
	if ((ret == 1 || *(*tmp)->str == '%') && (*tmp)->str++)
		return ((ft_printf_processing(ap, tmp)) ? (0) : (1));
	else if (ret != 1 && !search_specify(tmp))
		return (kostil(tmp));
	return (0);
}

void				fill_bits_1(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == 'd')
	{
		g_flags |= d;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'i')
	{
		g_flags |= i;
		*ret += 1;
	}
	else if (*(*tmp)->str == 's')
	{
		g_flags |= s;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'o')
	{
		g_flags |= o;
		*ret += 1;
	}
}

void				fill_bits_2(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == 'p')
	{
		g_flags |= p;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'x')
	{
		g_flags |= x;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'c')
	{
		g_flags |= c;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'C')
	{
		g_flags |= C;
		*ret += 1;
	}
}

void				fill_bits_3(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == 'u')
	{
		g_flags |= u;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'D')
	{
		g_flags |= D;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'S')
	{
		g_flags |= S;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'O')
	{
		g_flags |= O;
		*ret += 1;
	}
}

void				fill_bits_4(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == 'U')
	{
		g_flags |= U;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'X')
	{
		g_flags |= X;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'b')
	{
		g_flags |= b;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'B')
	{
		g_flags |= B;
		*ret += 1;
	}
}
