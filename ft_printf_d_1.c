/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:13:18 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/26 17:13:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				search_specify(t_alist **tmp)
{
	int			ret;

	ret = 0;
	(*(*tmp)->str == 'd' || g_flags & d) ? (ret = d) : (0);
	(*(*tmp)->str == 'i' || g_flags & i) ? (ret = i) : (0);
	(*(*tmp)->str == 's' || g_flags & s) ? (ret = s) : (0);
	(*(*tmp)->str == 'o' || g_flags & o) ? (ret = o) : (0);
	(*(*tmp)->str == 'p' || g_flags & p) ? (ret = p) : (0);
	(*(*tmp)->str == 'x' || g_flags & x) ? (ret = x) : (0);
	(*(*tmp)->str == 'c' || g_flags & c) ? (ret = c) : (0);
	(*(*tmp)->str == 'C' || g_flags & C) ? (ret = C) : (0);
	(*(*tmp)->str == 'u' || g_flags & u) ? (ret = u) : (0);
	(*(*tmp)->str == 'D' || g_flags & D) ? (ret = D) : (0);
	(*(*tmp)->str == 'S' || g_flags & S) ? (ret = S) : (0);
	(*(*tmp)->str == 'O' || g_flags & O) ? (ret = O) : (0);
	(*(*tmp)->str == 'U' || g_flags & U) ? (ret = U) : (0);
	(*(*tmp)->str == 'X' || g_flags & X) ? (ret = X) : (0);
	(*(*tmp)->str == 'b' || g_flags & b) ? (ret = b) : (0);
	(*(*tmp)->str == 'B' || g_flags & B) ? (ret = B) : (0);
	(*(*tmp)->str == 'k' || g_flags & k) ? (ret = k) : (0);
	return (ret);
}

int				isflag(void)
{
	int			a;

	a = 0;
	(g_flags & hh) ? (a += 1) : (0);
	(g_flags & h) ? (a += 1) : (0);
	(g_flags & l) ? (a += 1) : (0);
	(g_flags & ll) ? (a += 1) : (0);
	(g_flags & j) ? (a += 1) : (0);
	(g_flags & z) ? (a += 1) : (0);
	return (a);
}

int				search(void)
{
	int			a;

	a = 0;
	(g_flags & hh) ? (a = hh) : (0);
	(g_flags & h) ? (a = h) : (0);
	(g_flags & l) ? (a = l) : (0);
	(g_flags & ll) ? (a = ll) : (0);
	(g_flags & j) ? (a = j) : (0);
	(g_flags & z) ? (a = z) : (0);
	return (a);
}

int				kostil(t_alist **tmp)
{
	size_t		i;
	char		s[(*tmp)->j];

	i = 0;
	if (g_flags & width && !(g_flags & zero))
	{
		buffering(tmp, 1, 1, (*tmp)->str);
		return (1);
	}
	else if (g_flags & width && (g_flags & zero))
	{
		if (g_flags & zero)
		{
			ft_bchr(&s[i], '0', (*tmp)->j);
			i = (*tmp)->j;
		}
		ft_bchr(&s[i - 1], *(*tmp)->str, 1);
		g_flags ^= width;
		(*tmp)->j = 0;
		buffering(tmp, 1, i, s);
		return (1);
	}
	return (1);
}
