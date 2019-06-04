/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:02:14 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/01 14:53:34 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						base_str(intmax_t c, int up)
{
	if (c < 0)
		c = c * (-1);
	if (c >= 0 && c <= 9)
		return ((char)(c + 48));
	if (c >= 10 && c <= 16)
	{
		if (up)
			return ((char)(c + 65 - 10));
		else
			return ((char)(c + 97 - 10));
	}
	return (0);
}

inline void					ft_itoa_base_printf_s(intmax_t n,
							int base, int up, t_alist **tmp)
{
	int						i;
	signed long long int	num;
	char					str[lenght((uintmax_t)n, base) + 2];

	i = 0;
	num = n;
	if (n == 0)
	{
		(g_flags & presicions) ? (zero_decimal_integer(tmp, n))
		: (buffering(tmp, 0, 1, "0"));
		return ;
	}
	while (num != 0)
	{
		str[i] = base_str(num % base, up);
		num /= base;
		i++;
	}
	if (n < 0 && base == 10)
		str[i++] = '-';
	str[i] = '\0';
	swap(str, ft_strlen(str));
	if (hash_(tmp, ft_strlen(str), str))
		return ;
	buffering(tmp, 0, ft_strlen(&str[0]), &str[0]);
}
