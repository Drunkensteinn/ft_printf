/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:03:48 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:02:16 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	mark;

	str = (unsigned char *)s;
	mark = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == mark)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
