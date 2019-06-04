/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:57:50 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/05 17:07:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *format, ...)
{
	va_list				ag;
	static t_alist		*tmp;
	int					res;

	tmp = NULL;
	tmp = ft_alist_initialize(tmp, 0);
	tmp->str = (char *)format;
	tmp->tmp_1 = (char *)format;
	tmp->i = 0;
	tmp->n = 0;
	tmp->k = 0;
	tmp->extra3 = 0;
	tmp->extra2 = 0;
	tmp->len_format = 0;
	tmp->extra = 0;
	ft_bzero(tmp->buff, BUFF_SIZE);
	va_start(ag, format);
	res = ft_printf_core(ag, tmp);
	va_end(ag);
	g_flags = 0;
	free(tmp);
	return (res);
}

int						ft_fprintf(const int fd, const char *format, ...)
{
	va_list				ag;
	static t_alist		*tmp;
	int					res;

	tmp = NULL;
	tmp = ft_alist_initialize(tmp, 0);
	tmp->str = (char *)format;
	tmp->tmp_1 = (char *)format;
	tmp->i = 0;
	tmp->n = 0;
	tmp->k = 0;
	tmp->fd = fd;
	tmp->extra2 = 0;
	tmp->len_format = 0;
	tmp->extra = 0;
	ft_bzero(tmp->buff, BUFF_SIZE);
	va_start(ag, format);
	res = ft_printf_core(ag, tmp);
	va_end(ag);
	g_flags = 0;
	free(tmp);
	return (res);
}

inline int				ft_printf_core(va_list ag, t_alist *tmp)
{
	while (*tmp->str)
	{
		if (*tmp->str == '%')
		{
			tmp->str++;
			g_flags = 0;
			if (validator_specificators_and_flags(ag, &tmp))
				continue;
			else
			{
				pre_output1(&tmp, &(tmp->k));
				continue ;
			}
		}
		buffering(&tmp, 1, 1, "");
	}
	if (!*tmp->str)
		return (ft_printf_core_1(tmp));
	return (0);
}

inline int				ft_printf_core_1(t_alist *tmp)
{
	if (*tmp->buff && (tmp)->extra3 == 0)
	{
		(!*(tmp->buff) && (tmp->extra != 0) &&
				(tmp->size_bytes < tmp->extra)) ?
		(tmp->size_bytes = tmp->extra) : (0);
		output(tmp->fd, tmp->buff, tmp->size_bytes);
		return ((tmp->extra2 != 0) ?
				(int)(tmp->size_bytes + tmp->extra2) :
				(int)(tmp->size_bytes));
	}
	else if (*tmp->buff && (tmp)->extra3 != 0)
	{
		output(tmp->fd, tmp->buff, tmp->size_bytes);
		(tmp->extra3 > tmp->size_bytes) ?
		(tmp->size_bytes += tmp->extra3) : (0);
		tmp->extra3 = 0;
		return ((int)tmp->size_bytes);
	}
	(!*(tmp->buff) && (tmp->extra != 0) &&
			(tmp->size_bytes < tmp->extra))
	? (tmp->size_bytes = tmp->extra) : (0);
	return ((int)tmp->size_bytes);
}

inline int				validator_specificators_and_flags(va_list ap,
t_alist **tmp)
{
	while (*(*tmp)->str && *(*tmp)->str != '%')
	{
		if (fill_bits_a(tmp))
			continue ;
		if (width_(tmp))
			continue ;
		if (presic_(tmp))
			continue ;
		if (validator_flags(tmp))
			continue ;
		return (!fill_bits(tmp, ap));
	}
	return (0);
}
