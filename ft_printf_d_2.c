/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:13:30 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/26 17:13:31 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		width_(t_alist **tmp)
{
	if (g_flags & width)
		return (0);
	if (*(*tmp)->str >= '1' && *(*tmp)->str <= '9')
	{
		(*tmp)->j = (size_t)ft_atoi((*tmp)->str);
		g_flags |= width;
	}
	while (*(*tmp)->str >= '0' && *(*tmp)->str <= '9')
		(*tmp)->str++;
	if ((*tmp)->j != 0)
		return (1);
	return (0);
}

inline int		fill_bits_a(t_alist **tmp)
{
	int			ret;

	ret = 0;
	fill_bits_a_1(tmp, &ret);
	fill_bits_a_2(tmp, &ret);
	if (ret >= 1)
		return (1);
	return (0);
}

inline void		fill_bits_a_1(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == '#' && !search_specify(tmp))
	{
		g_flags |= hash;
		(*tmp)->str += 1;
		*ret += 1;
	}
	else if (*(*tmp)->str == '0' && !search_specify(tmp))
	{
		g_flags |= zero;
		(*tmp)->str += 1;
		*ret += 1;
	}
	else if (*(*tmp)->str == '+' && !search_specify(tmp))
	{
		g_flags |= plus;
		(*tmp)->str += 1;
		*ret += 1;
	}
	else if (*(*tmp)->str == '-' && !search_specify(tmp))
	{
		g_flags |= minus;
		(*tmp)->str += 1;
		*ret += 1;
	}
}

inline void		fill_bits_a_2(t_alist **tmp, int *ret)
{
	if (*(*tmp)->str == ' ' && !search_specify(tmp))
	{
		g_flags |= space;
		(*tmp)->str += 1;
		*ret += 1;
	}
	else if (*(*tmp)->str == 'n' && !search_specify(tmp))
	{
		g_flags |= n;
		(*tmp)->str += 1;
		*ret += 1;
	}
	else if (*(*tmp)->str == '$' && !search_specify(tmp))
	{
		g_flags |= dollar;
		(*tmp)->str += 1;
		*ret += 1;
	}
}

inline int		copy_string(t_alist **tmp)
{
	ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes],
	(*tmp)->str, ft_strlen((*tmp)->str));
	return (1);
}
