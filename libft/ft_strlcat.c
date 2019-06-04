/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:25:12 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:05:47 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	ssize;
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	len = dstsize - dsize - 1;
	i = dsize + ssize;
	if (dsize >= dstsize)
		return (ssize + dstsize);
	else
	{
		str = ft_strncat(dst, src, len);
		return (i);
	}
	return (i);
}
