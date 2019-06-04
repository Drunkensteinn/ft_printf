/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:50:22 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:13:51 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = (void *)0;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (str && i < size)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (str);
}
