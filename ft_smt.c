/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 21:35:38 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/27 21:35:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_bzero_list(t_alist **tmp)
{
	(*tmp)->a = 1;
	(*tmp)->b = 2;
	(*tmp)->c = 3;
	(*tmp)->d = 4;
}

inline int		space_1(t_alist **tmp, size_t len, char *str, char *symbol)
{
	char s[(*tmp)->n + len + 1];

	s[(*tmp)->n + 1] = '\0';
	if ((g_flags & space) && ((g_flags & d) || (g_flags & i))
	&& !(g_flags & plus) &&
	!(g_flags & minus) && *symbol != '-' && !(g_flags & presicions) &&
	!(*tmp)->j && !(g_flags & u || g_flags & U))
	{
		s[0] = ' ';
		ft_memcpy(&s[1], symbol, len);
		ft_memcpy(str, s, (*tmp)->n + len + 1);
		(*tmp)->n += 1;
		return (1);
	}
	else if ((g_flags & space) && ((g_flags & d) ||
			(g_flags & i)) && (g_flags & presicions) && (*tmp)->j < (*tmp)->k)
	{
		s[0] = ' ';
		ft_memcpy(&s[1], symbol, len);
		ft_memcpy(str, s, (*tmp)->n + len + 1);
		(*tmp)->n += 1;
		return (1);
	}
	return (0);
}

void			buffering_2(t_alist **tmp, int step)
{
	if (*(*tmp)->str)
	{
		(*tmp)->j = 0;
		(*tmp)->str = (*tmp)->str + step;
		((*tmp)->extra != 0) ? ((*tmp)->extra += 1) : (0);
	}
}

inline void		d_d_i_presisions(t_alist **tmp, size_t l, char *str, int *res)
{
	char s[(*tmp)->k + 2];

	s[(*tmp)->k] = '\0';
	if ((*tmp)->k > l && *str != '-')
	{
		ft_bchr(s, '0', (*tmp)->k - l);
		ft_memcpy(&s[(*tmp)->k - l], str, l);
		*res += 1;
		buffering(tmp, 0, (*tmp)->k, s);
		return ;
	}
	else if ((*tmp)->k >= l && *str == '-')
	{
		str++;
		s[0] = '-';
		ft_bchr(&s[1], '0', (*tmp)->k - l + 1);
		ft_memcpy(&s[(*tmp)->k - l + 2], str, l);
		*res += 1;
		buffering(tmp, 1, (*tmp)->k + 1, s);
		return ;
	}
	else if ((*tmp)->k == 0 && g_flags & presicions && (*tmp)->j)
		buffering(tmp, 0, 0, "");
}

inline void		u_u_presisions(t_alist **tmp, size_t l, char *str, int *res)
{
	char s[(*tmp)->k];

	s[(*tmp)->k] = '\0';
	if ((*tmp)->k > l)
	{
		ft_bchr(s, '0', (*tmp)->k - l);
		ft_memcpy(&s[(*tmp)->k - l], str, l);
		*res += 1;
		buffering(tmp, 1, (*tmp)->k, s);
	}
}
