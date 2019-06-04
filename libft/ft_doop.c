/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:05:54 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 18:12:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_doop(int a, const char b, int c)
{
	if (!b)
		return (0);
	if (!a || !c)
		return (0);
	if (b == '+')
		return (a + c);
	if (b == '-')
		return (a - c);
	if (b == '*')
		return (a * c);
	if (b == '/')
		return (a / c);
	if (b == '%')
		return (a % c);
	return (0);
}
