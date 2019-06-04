/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_0_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:14:37 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 18:14:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		ft_printf_processing(va_list ap, t_alist **tmp)
{
	if (ft_printf_processing_1(ap, tmp))
		return (1);
	if (ft_printf_processing_2(ap, tmp))
		return (1);
	if (ft_printf_processing_3(ap, tmp))
		return (1);
	if (ft_printf_processing_4(ap, tmp))
		return (1);
	if (ft_printf_processing_5(ap, tmp))
		return (1);
	else if (*(*tmp)->str == '%')
	{
		buffering(tmp, 0, 1, "");
		return (1);
	}
	return (0);
}
