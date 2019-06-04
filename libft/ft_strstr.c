/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:47:39 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:08:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*str1;
	char	*str2;
	size_t	size1;
	size_t	size2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	size1 = ft_strlen(str2);
	size2 = ft_strlen(str1);
	if (size1 == 0)
		return (str1);
	if (size1 == 0 && size2 == 0)
		return (0);
	while (str1[i] != '\0')
	{
		if (ft_strncmp(&str1[i], str2, size1) == 0)
			return (&str1[i]);
		i++;
	}
	return (NULL);
}
