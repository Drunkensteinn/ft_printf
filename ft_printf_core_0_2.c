/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_0_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 23:14:47 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/26 23:14:48 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			pointer_prec_zero(t_alist **tmp)
{
	char			s[(*tmp)->k + 2];

	s[0] = '0';
	s[1] = 'x';
	ft_bchr(&s[2], '0', (*tmp)->k);
	buffering(tmp, 0, (*tmp)->k + 2, s);
	return ;
}

inline void			pointer_addres(t_alist **tmp, size_t len, char *symbol)
{
	char		s[len + 2 + (*tmp)->k];

	s[len + 3] = '\0';
	if (g_flags & presicions && (*tmp)->k > len)
	{
		s[0] = '0';
		s[1] = 'x';
		ft_bchr(&s[2], '0', (*tmp)->k - len);
		ft_memcpy(&s[2 + (*tmp)->k - len], symbol, len);
		buffering(tmp, 0, (*tmp)->k + 2, s);
		return ;
	}
	s[0] = '0';
	s[1] = 'x';
	ft_memcpy(&s[2], symbol, len);
	buffering(tmp, 0, len + 2, s);
}

inline void			c_character(t_alist **tmp, va_list ap)
{
	char			f;

	if (search() == l)
	{
		unicode_c(tmp, ap);
		g_flags ^= l;
	}
	else
	{
		f = (char)va_arg(ap, unsigned int);
		(f == '\0') ? (c_eof(tmp)) : (buffering(tmp, 0, 1, &f));
	}
}

inline void			format_len(t_alist **tmp)
{
	while ((*tmp)->tmp_1[(*tmp)->len_format] != '\0')
		(*tmp)->len_format++;
}

inline void			c_eof(t_alist **tmp)
{
	format_len(tmp);
	if ((*tmp)->j && width_c_eof(tmp))
		return ;
	if ((*tmp)->j && width_c_zero(tmp))
		return ;
	(*tmp)->size_bytes += 1;
	output((*tmp)->fd, (*tmp)->buff, (*tmp)->size_bytes);
	ft_bzero((*tmp)->buff, BUFF_SIZE);
	(*tmp)->extra = (*tmp)->size_bytes;
	(*tmp)->size_bytes = 0;
	if (*(*tmp)->str)
	{
		ft_memcpy((*tmp)->buff, (*tmp)->str, (ft_strchr((*tmp)->str, '%')) ?
		(ft_strchr((*tmp)->str, '%') - (*tmp)->str) :
		((*tmp)->len_format - (*tmp)->extra));
		output((*tmp)->fd, (*tmp)->buff, (*tmp)->len_format -
		(*tmp)->extra - 1);
		ft_bzero((*tmp)->buff, BUFF_SIZE);
	}
}
