/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:57:23 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:18:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str1;
	char	*str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (len1 != len2)
		return (0);
	if (len1 == len2)
	{
		while (i < len1)
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
