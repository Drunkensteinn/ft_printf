/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:03:14 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:39:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(char const *str, size_t len)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (len == 0)
		return (ft_strlen(str));
	while (str[i] != '\0' && i < len)
		i++;
	return (i);
}
