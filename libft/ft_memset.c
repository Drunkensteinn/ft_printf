/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:59:45 by ablizniu          #+#    #+#             */
/*   Updated: 2017/11/29 20:09:36 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	str;

	a = b;
	str = (unsigned char)c;
	if (len == 0)
		return (b);
	while (len)
	{
		*a = str;
		if (len)
			a++;
		len--;
	}
	return (b);
}
