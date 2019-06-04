/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:15:19 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:06:42 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	str1;

	i = 0;
	str = (char *)s;
	str1 = (char)c;
	while (str[i])
	{
		if (str[i] == str1)
		{
			return (&str[i]);
			break ;
		}
		i++;
	}
	if (str[i] == str1)
		return (&str[i]);
	return (NULL);
}
