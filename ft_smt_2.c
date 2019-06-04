/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 22:39:06 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 22:39:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		x_x_zero_width(t_alist **tmp, size_t l, char *str)
{
	char s[(*tmp)->j];

	s[(*tmp)->j] = '\0';
	if (((*tmp)->j) > l && (g_flags & zero) &&
			!(g_flags & minus) && !(g_flags & presicions))
	{
		if (g_flags & X)
		{
			s[0] = '0';
			s[1] = 'X';
		}
		if (g_flags & x)
		{
			s[0] = '0';
			s[1] = 'x';
		}
		(*tmp)->j -= 2;
		ft_bchr(&s[2], '0', ((*tmp)->j > l) ? ((*tmp)->j - l) : (0));
		ft_memcpy(&s[((*tmp)->j > l) ? ((*tmp)->j - l + 2) : (2)], str, l);
		g_flags = 0;
		buffering(tmp, 0, (*tmp)->j + l, &s[0]);
		return (1);
	}
	return (0);
}

inline int		zero_decimal_integer(t_alist **tmp, intmax_t n)
{
	size_t		l;
	char		s[2];

	l = 1;
	if (n == 0 && (*tmp)->k == 0 && (*tmp)->j == 0)
		return (1);
	else
	{
		s[0] = '0';
		hash_(tmp, l, s);
	}
	s[1] = '\0';
	(*tmp)->n = 0;
	return (1);
}

inline int		x_x_precision(t_alist **tmp, size_t l, char *str, int *res)
{
	char		s[(*tmp)->k];

	s[(*tmp)->k] = '\0';
	if ((*tmp)->k > l && (*tmp)->k > 0 && *str)
	{
		ft_bchr(&s[0], '0', ((*tmp)->k > l) ? ((*tmp)->k - l) : (0));
		ft_memcpy(&s[((*tmp)->k > l) ? ((*tmp)->k - l) : (0)], str, l);
		s[(*tmp)->k + l] = '\0';
		buffering(tmp, 0, (*tmp)->k, s);
		*res = 1;
		return (1);
	}
	else if ((*tmp)->k <= l && *str)
	{
		buffering(tmp, 0, l, str);
		*res = 1;
		return (1);
	}
	*res = 0;
	return (0);
}

inline int		o_o_precision(t_alist **tmp, size_t l, char *str, int *res)
{
	char		s[(*tmp)->k];

	s[(*tmp)->k] = '\0';
	if ((*tmp)->k > l && (*tmp)->k > 0 && *str)
	{
		ft_bchr(&s[0], '0', ((*tmp)->k > l) ? ((*tmp)->k - l) : (0));
		ft_memcpy(&s[((*tmp)->k > l) ? ((*tmp)->k - l) : (0)], str, l);
		s[(*tmp)->k + l] = '\0';
		buffering(tmp, 0, (*tmp)->k, s);
		*res = 1;
		return (1);
	}
	else if ((*tmp)->k <= l && *str)
	{
		buffering(tmp, 0, l, str);
		*res = 1;
		return (1);
	}
	*res = 0;
	return (0);
}

inline int		s_s_precision(t_alist **tmp, size_t l, char *str)
{
	if ((*tmp)->k > l && *str)
	{
		buffering(tmp, 0, l, str);
		return (1);
	}
	else if ((g_flags & presicions) && (*tmp)->k <= l && *str)
	{
		buffering(tmp, 0, (*tmp)->k, str);
		return (1);
	}
	else if (!(g_flags & presicions) && *str)
	{
		buffering(tmp, 0, l, str);
		return (1);
	}
	else
		buffering(tmp, 0, 0, " ");
	return (0);
}
