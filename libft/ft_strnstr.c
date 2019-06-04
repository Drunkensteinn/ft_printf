/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:36:55 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:01:47 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	if (s2 == s1 || s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		if (s1[i] == *s2)
		{
			b = i++;
			s2++;
			while (s1[i] == *s2 && s1[i] && *s2 && i++ < len && b < len)
				s2++;
			if (*s2 == '\0')
				return ((char *)&s1[b]);
			else
			{
				s2 = s2 - (i - b);
				i = b + 1;
			}
		}
		i++;
	}
	return (NULL);
}
