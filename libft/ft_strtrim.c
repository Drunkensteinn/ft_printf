/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:22:25 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:24:22 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	buffer;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	if (len == 0)
		return (0);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > i)
		len--;
	buffer = len - i + 1;
	if (buffer + 1 == 0)
		return (0);
	str = ft_strsub((char *)s, i, buffer);
	return (str);
}
