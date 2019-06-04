/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:11:45 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 19:11:55 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				plus_(t_alist **tmp, char **symbol, char *str)
{
	if ((*str != '-') && (**symbol != '-') &&
	(g_flags & plus) && (g_flags & zero))
		str[0] = '+';
	if ((g_flags & plus) && (**symbol != '-') &&
	!(g_flags & zero) && !(g_flags & minus) && *str)
		str[ft_strlen(str) - 1] = '+';
	if ((g_flags & plus) && !(g_flags & zero) &&
	(g_flags & minus) && (**symbol != '-'))
		str[0] = '+';
	else if ((g_flags & plus) && (**symbol != '-') &&
	(g_flags & minus))
	{
		str[0] = '+';
		((*tmp)->j) ? ((*tmp)->j--) : (0);
	}
	else if ((g_flags & plus) && (**symbol != '-') &&
	*str != '-' && !(g_flags & zero) && !(*tmp)->j)
	{
		str[0] = '+';
		((*tmp)->j) ? ((*tmp)->j--) : (0);
	}
}

inline void			space_(t_alist **tmp, size_t len, char *str, char *symbol)
{
	char			s[(*tmp)->n + len + 1];

	s[(*tmp)->n + 1] = '\0';
	if (g_flags & space && g_flags & presicions && !(*tmp)->j &&
	!(g_flags & plus) && *symbol != '-' && !(g_flags & u || g_flags & U))
	{
		s[0] = ' ';
		ft_memcpy(&s[1], str, (*tmp)->n);
		ft_memcpy(str, s, (*tmp)->n + 1);
		(*tmp)->n += 1;
		return ;
	}
	else if (g_flags & space && !(g_flags & plus) && !(g_flags & minus) &&
			!(g_flags & presicions) && (*tmp)->j && *symbol != '-' &&
			!(g_flags & u || g_flags & U))
	{
		str[0] = ' ';
		return ;
	}
	if (space_1(tmp, len, str, symbol))
		return ;
}

inline void			buffering(t_alist **tmp, int step,
					size_t size, char *symbol)
{
	char			s[(*tmp)->j + size + 1];

	ft_bzero(&s[0], (*tmp)->j + size + 1);
	if (!*symbol)
	{
		(*tmp)->size_bytes += BUFF_LEN + (*tmp)->extra;
		if (pre_output1(tmp, &size))
			return ;
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], (*tmp)->str, size);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
	}
	else
	{
		min_(tmp, &symbol, &size, &s[0]);
		plus_(tmp, &symbol, &s[0]);
		(*tmp)->n = ft_strlen(&s[0]);
		pre_output2(tmp, size, &s[0], symbol);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
	}
	buffering_2(tmp, step);
}

inline void			pre_output2(t_alist **tmp,
					size_t l2, char *str, char *symbol)
{
	if (l2 + (*tmp)->size_bytes > BUFF_SIZE)
	{
		if (pre_output_2_1(tmp, l2, symbol))
			return ;
		else
		{
			pre_output_2_2(tmp, symbol);
			l2 -= BUFF_SIZE;
			symbol += BUFF_SIZE;
		}
		pre_output2(tmp, l2, str, symbol);
		return ;
	}
	if (kostili(tmp, l2, str, symbol))
		return ;
	pre_output_2_3(tmp, l2, symbol, str);
}

void				pre_output_2_3(t_alist **tmp,
					size_t l2, char *symbol, char *str)
{
	char			str_res[(*tmp)->n + l2 + 1];
	static size_t	i;

	i = 0;
	str_res[(*tmp)->n + l2 + 1] = '\0';
	ft_memcpy(&str_res[i], str, (*tmp)->n);
	space_(tmp, l2, &str_res[0], symbol);
	i = (*tmp)->n;
	ft_memcpy(&str_res[i], symbol, l2);
	str_res[(*tmp)->n + l2] = '\0';
	i = 0;
	ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes],
				&str_res[i], l2 + (*tmp)->n);
}
