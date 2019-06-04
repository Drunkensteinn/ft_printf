/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:11:31 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:07:22 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	i = 0;
	str = (char *)s;
	a = (char)c;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == a)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
