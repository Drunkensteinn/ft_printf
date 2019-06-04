/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:20:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/07 14:13:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					*unicode_len(wchar_t *arr)
{
	unsigned int	value;
	unsigned int	len[4];
	int				len_s[2];
	int				*s;

	ft_bzero_int((int *)len_s, 2);
	ft_bzero_int((int *)len, 4);
	while (*arr)
	{
		value = (unsigned int)*arr;
		(value <= 0x80) ? ((len[0])++) : (0);
		(value > 0x80 && value <= 0x800) ? ((len[1])++) : (0);
		(value > 0x800 && value <= 0x8000) ? ((len[2])++) : (0);
		(value > 0x8000) ? ((len[3])++) : (0);
		arr++;
	}
	len_s[0] += len[0] * 1;
	len_s[0] += len[1] * 2;
	len_s[0] += len[2] * 3;
	len_s[0] += len[3] * 4;
	(len[1] != 0) ? (len_s[1] = 2) : (0);
	(len[2] != 0) ? (len_s[1] = 3) : (0);
	(len[3] != 0) ? (len_s[1] = 4) : (0);
	s = len_s;
	return (s);
}

inline void			min_(t_alist **tmp, char **symbol, size_t *size, char *str)
{
	(!(g_flags & minus)) ? (w_m(tmp, size, symbol, str)) :
	(ft_bchr(str, ' ', (size_t)(*tmp)->j));
}

inline void			w_m(t_alist **tmp, size_t *size, char **symbol, char *str)
{
	(*tmp)->n = 0;
	while (((*tmp)->j > *size))
	{
		(g_flags & zero) ? (p_m(tmp, symbol, size, str)) :
		(str[(*tmp)->n] = ' ');
		(*tmp)->n++;
		(*tmp)->j--;
	}
	(*tmp)->n = 0;
}

inline void			p_m(t_alist **tmp, char **symbol, size_t *size, char *str)
{
	if (!(g_flags & presicions))
		(**symbol == '-') ? ((ft_memcpy(str, "-", 1)) && (*symbol)++
	&& (*size -= 1)) :
	(void)(ft_memcpy(&str[(*tmp)->n], "0", 1));
	else if ((g_flags & presicions))
		str[(*tmp)->n] = ' ';
}
