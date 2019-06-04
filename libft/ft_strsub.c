/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:03:00 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:23:35 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*sub_str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (*str != '\0' && i < len)
	{
		sub_str[i] = str[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
