/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:11 by ablizniu          #+#    #+#             */
/*   Updated: 2018/02/19 19:12:22 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memjoin(void *s1, size_t s1_size,
					void *s2, size_t s2_size)
{
	unsigned char	*str;

	str = NULL;
	if (s2 == NULL && s1)
	{
		str = ft_memalloc(s1_size);
		ft_memcpy(str, s1, s1_size);
		ft_memdel(&s1);
		return (str);
	}
	if (s1 == NULL && s2)
	{
		str = ft_memalloc(s2_size);
		ft_memcpy(str, s2, s2_size);
		ft_memdel(&s2);
		return (str);
	}
	str = (unsigned char *)ft_memalloc(s1_size + s2_size);
	ft_memcpy(str, s1, s1_size);
	ft_memcpy(str + s1_size, s2, s2_size);
	return (s1);
}
