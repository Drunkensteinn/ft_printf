/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:23:37 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:43:07 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char const *s)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return ;
	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
