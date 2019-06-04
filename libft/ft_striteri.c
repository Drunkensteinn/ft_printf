/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:56:59 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:16:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL && f == NULL)
		return ;
	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		s++;
		i++;
	}
}
