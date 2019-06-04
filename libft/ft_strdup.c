/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:07:32 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:03:48 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;
	char	*str1;

	i = 0;
	j = 0;
	str = (char *)s1;
	i = ft_strlen(s1);
	if (!(str1 = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (j < i)
	{
		str1[j] = str[j];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}
