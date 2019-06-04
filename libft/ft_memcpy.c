/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:20:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/10 17:26:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	char unsigned		*s1;
	char unsigned		*s2;

	s1 = (char unsigned *)dst;
	s2 = (char unsigned *)src;
	while (n != 0)
	{
		*s1++ = *s2++;
		n--;
	}
	return (dst);
}
