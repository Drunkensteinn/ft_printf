/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:00:58 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:14:26 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (!*ap)
		return ;
	if (*ap != (void *)0 || ap != (void *)0)
	{
		free(*ap);
		*ap = (void *)0;
	}
}
