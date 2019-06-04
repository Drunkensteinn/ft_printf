/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_printf_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:38:23 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/01 14:44:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char unsigned	base_str_u(intmax_t c, int up)
{
	if (c >= 0 && c <= 9)
		return ((char unsigned)(c + 48));
	if (c >= 10 && c <= 16)
	{
		if (up)
			return ((char unsigned)(c + 65 - 10));
		else
			return ((char unsigned)(c + 97 - 10));
	}
	return (0);
}

inline void		ft_itoa_base_printfu(uintmax_t num, int base,
int up, t_alist **tmp)
{
	int			i;
	size_t		l;
	char		str[lenght(num, base)];

	i = 0;
	l = lenght(num, base);
	str[l] = '\0';
	if (num == 0 && !(g_flags & presicions) && !(g_flags & p))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], "0", 1);
		(*tmp)->size_bytes += 1;
		return ;
	}
	while (num != 0)
	{
		str[i] = base_str_u((uintmax_t)num % base, up);
		num /= base;
		i++;
	}
	str[++i] = '\0';
	swap((char *)str, ft_strlen((char *)str));
	if (hash_(tmp, l, str))
		return ;
	buffering(tmp, 0, ft_strlen(str), str);
}
