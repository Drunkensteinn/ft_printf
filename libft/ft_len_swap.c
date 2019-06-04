/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:32:13 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/08 18:32:14 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		lenght(uintmax_t num, int base)
{
	size_t	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / base;
	}
	return (i);
}

void		swap(char *str, size_t len)
{
	size_t	i;
	char	c;

	i = 0;
	len--;
	if (!*str)
		return ;
	while (len > i)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		i++;
		len--;
	}
}
