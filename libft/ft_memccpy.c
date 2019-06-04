/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:18:04 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/05 23:28:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	mark;

	i = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	mark = (unsigned char)c;
	while (n != 0)
	{
		str1[i] = str2[i];
		if (str2[i] == mark)
			return (&str1[i] + 1);
		i++;
		n--;
	}
	return (NULL);
}
