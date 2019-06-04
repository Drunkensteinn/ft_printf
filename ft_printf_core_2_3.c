/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:00:04 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 19:00:16 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			unicode_0(t_alist **tmp,
					unsigned int value, char *arr, int *step)
{
	char			f[2];

	f[0] = (char)value;
	f[1] = '\0';
	if (!(g_flags & C))
	{
		*step = 1;
		make_us_whole_reference_to_dead_space(tmp, *step, arr, f);
	}
	else
		buffering(tmp, 0, 1, f);
}

inline void			unicode_1(t_alist **tmp,
					unsigned int value, char *arr, int *step)
{
	unsigned char	octet[4][1];
	unsigned int	o_m[4];
	unsigned char	res[2];

	o_m[1] = (value & 0x3f);
	o_m[0] = ((value >> 6) & 0x3f);
	res[1] = '\0';
	octet[0][0] = (unsigned char)((SECOND >> 8) | o_m[0]);
	ft_memcpy(&res[0], (void *)octet[0], 1);
	octet[1][0] = (unsigned char)((SECOND & 0x80) | o_m[1]);
	ft_memcpy(&res[1], (void *)octet[1], 1);
	*step = 2;
	make_us_whole_reference_to_dead_space(tmp, *step, arr, (char *)&res[0]);
}

inline void			unicode_2(t_alist **tmp,
					unsigned int value, char *arr, int *step)
{
	unsigned char	octet[4][1];
	unsigned int	o_m[4];
	unsigned char	res[3];

	o_m[0] = (value & 0x3f);
	o_m[1] = (value >> 6) & 0x3f;
	o_m[2] = (value >> 12) & 0x3f;
	octet[0][0] = (unsigned char)((THIRD >> 16) | o_m[2]);
	ft_memcpy(&res[0], (void *)octet[0], 1);
	octet[1][0] = (unsigned char)(((THIRD >> 8) & 0x80) | o_m[1]);
	ft_memcpy(&res[1], (void *)octet[1], 1);
	octet[2][0] = (unsigned char)(((THIRD & 0x80) | o_m[0]));
	ft_memcpy(&res[2], (void *)octet[2], 1);
	*step = 3;
	make_us_whole_reference_to_dead_space(tmp, *step, arr, (char *)&res[0]);
}

inline void			unicode_3(t_alist **tmp,
					unsigned int value, char *arr, int *step)
{
	unsigned char	octet[4][1];
	unsigned int	o_m[4];
	unsigned char	res[4];

	o_m[0] = (value & 0x3f);
	o_m[1] = (value >> 6) & 0x3f;
	o_m[2] = (value >> 12) & 0x3f;
	o_m[3] = (value >> 20) & 0x7;
	octet[0][0] = (unsigned char)((FOURTH >> 24) | o_m[3]);
	ft_memcpy(&res[0], (void *)octet[0], 1);
	octet[1][0] = (unsigned char)(((FOURTH >> 16) & 0x80) | o_m[2]);
	ft_memcpy(&res[1], (void *)octet[1], 1);
	octet[2][0] = (unsigned char)(((FOURTH >> 8) & 0x80) | o_m[1]);
	ft_memcpy(&res[2], (void *)octet[2], 1);
	octet[3][0] = (unsigned char)((FOURTH & 0x80) | o_m[0]);
	ft_memcpy(&res[3], (void *)octet[3], 1);
	*step = 4;
	make_us_whole_reference_to_dead_space(tmp, *step, arr, (char *)&res[0]);
}

inline void			unicode_c(t_alist **tmp, va_list ap)
{
	wchar_t			val;
	unsigned int	value;

	ft_bzero_list(tmp);
	val = (va_arg(ap, wchar_t));
	value = (unsigned int)val;
	if (value == 0)
	{
		(*tmp)->size_bytes += 1;
		(*tmp)->extra2 += 1;
		output((*tmp)->fd, (*tmp)->buff, (*tmp)->size_bytes);
		return ;
	}
	(value <= 0x80) ? (unicode_0(tmp, value, NULL, &(*tmp)->a)) : (0);
	((value > 0x80 && value <= 0x800)) ?
	(unicode_1(tmp, value, NULL, &(*tmp)->b)) : (0);
	((value > 0x800 && value <= 0xFFFF)) ?
	(unicode_2(tmp, value, NULL, &(*tmp)->c)) : (0);
	(value > 0xFFFF) ? (unicode_3(tmp, value, NULL, &(*tmp)->d)) : (0);
}
