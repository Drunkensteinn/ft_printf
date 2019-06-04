/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smt_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:00:59 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 23:01:00 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int				hash_(t_alist **tmp, size_t l, char *str)
{
	int					res;

	res = 0;
	(g_flags & hash && (g_flags & O || g_flags & o)) ?
	(p_h_1(tmp, str, l, &res)) : (0);
	(g_flags & hash && (g_flags & X || g_flags & x)) ?
	(p_h_2(tmp, str, l, &res)) : (0);
	((g_flags & presicions) && (g_flags & X || g_flags & x) && res == 0) ?
	((x_x_precision(tmp, l, str, &res))) : (0);
	((g_flags & presicions) && (g_flags & O || g_flags & o) && res == 0) ?
	((o_o_precision(tmp, l, str, &res))) : (0);
	((g_flags * presicions) && (g_flags & d || g_flags & i || g_flags & D)) ?
	(d_d_i_presisions(tmp, l, str, &res)) : (0);
	((g_flags * presicions) && (g_flags & u || g_flags & U)) ?
	(u_u_presisions(tmp, l, str, &res)) : (0);
	((g_flags & p)) ? (p_h_3(tmp, str, l, &res)) : (0);
	if (res != 0)
	{
		g_flags = 0;
		ft_bzero(str, l);
		return (1);
	}
	return (0);
}

inline int				hash_and_presic_x_x(t_alist **tmp, size_t l, char *str)
{
	char				s[(*tmp)->k + l + 2];

	s[(*tmp)->k + l + 2] = '\0';
	if ((g_flags & presicions) && ((*tmp)->k) > l)
	{
		p_h_4(&s[0]);
		ft_bchr(&s[2], '0', (*tmp)->k - l + 2);
		ft_memcpy(&s[(*tmp)->k - l + 2], str, l);
		s[(*tmp)->k + l + 1] = '\0';
		if (g_flags & x)
			g_flags ^= x;
		buffering(tmp, 0, (size_t)(*tmp)->k + 2, &s[0]);
		return (1);
	}
	else if (x_x_zero_width(tmp, l, str))
		return (1);
	else if (*str)
	{
		p_h_5(&s[0]);
		ft_memcpy(&s[2], str, l);
		s[l + 2] = '\0';
		buffering(tmp, 0, l + 2, &s[0]);
		return (1);
	}
	return (0);
}

inline int				hash_and_presic_o_o(t_alist **tmp, size_t l, char *str)
{
	char				s[(*tmp)->k + l + 2];

	s[(*tmp)->k + l + 2] = '\0';
	if ((g_flags & presicions) && ((*tmp)->k) > l)
	{
		(g_flags & hash) ? ((s[0] = '0')) : (0);
		ft_bchr(&s[1], '0', (*tmp)->k - l);
		ft_memcpy(&s[(*tmp)->k - l], str, l);
		s[(*tmp)->k + l] = '\0';
		buffering(tmp, 0, (size_t)(*tmp)->k, &s[0]);
		return (1);
	}
	else
	{
		((g_flags & O)) ? ((s[0] = '0')) : (0);
		((g_flags & o)) ? ((s[0] = '0')) : (0);
		ft_memcpy(&s[1], str, l);
		s[l + 1] = '\0';
		buffering(tmp, 0, l + 1, &s[0]);
		str[0] = '\0';
		return (1);
	}
	return (0);
}
