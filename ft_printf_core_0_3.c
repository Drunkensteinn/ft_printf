/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_0_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:50:28 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 17:50:30 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void	x_hex(t_alist **tmp, va_list ap)
{
	(isflag()) ? (ft_itoa_base_printfu(isflags_unsigned(ap), 16, 0, tmp)) :
	(ft_itoa_base_printfu(va_arg(ap, unsigned int), 16, 0, tmp));
}

inline void	b_binary(t_alist **tmp, va_list ap)
{
	(isflag()) ? (ft_itoa_base_printfu(isflags_unsigned(ap), 2, 0, tmp)) :
	(ft_itoa_base_printfu(va_arg(ap, unsigned long int), 2, 0, tmp));
}

inline void	d_i(t_alist **tmp, va_list ap)
{
	(isflag()) ? (ft_itoa_base_printf_s(isflags_signed(ap), 10, 0, tmp)) :
	(ft_itoa_base_printf_s(va_arg(ap, int), 10, 0, tmp));
}

inline void	u_u(t_alist **tmp, va_list ap)
{
	(isflag()) ? (ft_itoa_base_printfu(isflags_unsigned(ap), 10, 0, tmp)) :
	(ft_itoa_base_printfu(va_arg(ap, unsigned int), 10, 0, tmp));
}

inline void	o_t(t_alist **tmp, va_list ap)
{
	(isflag()) ? (ft_itoa_base_printfu(isflags_unsigned(ap), 8, 0, tmp)) :
	(ft_itoa_base_printfu(va_arg(ap, unsigned int), 8, 0, tmp));
}
