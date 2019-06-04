/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:36:32 by ablizniu          #+#    #+#             */
/*   Updated: 2018/02/27 20:36:34 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *src, size_t size)
{
	void	*dst;
	size_t	i;

	i = 0;
	dst = NULL;
	if (size == 0)
	{
		ft_memdel(&src);
		return (NULL);
	}
	if (src == NULL)
	{
		dst = ft_memalloc(0);
		return (dst);
	}
	dst = ft_memalloc(size);
	ft_memcpy(dst, src, size);
	ft_memdel(&src);
	return (dst);
}
