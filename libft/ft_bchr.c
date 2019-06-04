/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:50:05 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/27 20:54:40 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bchr(const void *dst, char chr, size_t len)
{
	char	*dest;

	if (len == 0)
		return ;
	dest = (char *)dst;
	while (len)
	{
		*dest = chr;
		dest++;
		len--;
	}
}
