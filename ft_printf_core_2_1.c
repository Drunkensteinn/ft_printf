/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:52:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/27 18:52:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		kostili(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if (kostil_1(tmp, l2, str, symbol))
		return (1);
	if (kostil_2(tmp, l2, str, symbol))
		return (1);
	if (kostil_3(tmp, l2, str, symbol))
		return (1);
	if (kostil_4(tmp, l2, str, symbol))
		return (1);
	if (kostil_5(tmp, l2, str, symbol))
		return (1);
	if (kostil_6(tmp, l2, str, symbol))
		return (1);
	if (kostil_7(tmp, l2, str, symbol))
		return (1);
	if (kostil_8(tmp, l2, str, symbol))
		return (1);
	return (0);
}

inline int		kostil_1(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if ((g_flags & plus) && (g_flags & minus) && (str[0] == '+'))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes + 1], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_2(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if ((g_flags & plus) && (g_flags & minus) && (symbol[0] == '-'))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_3(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if (((g_flags & minus) && (g_flags & zero) && (symbol[0] != '-')))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}

inline int		kostil_4(t_alist **tmp, size_t l2, char *str, char *symbol)
{
	if (((g_flags & minus) && (g_flags & zero) &&
	!(g_flags & plus) && (*symbol == '-')))
	{
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], str, (*tmp)->n);
		ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, l2);
		(*tmp)->size_bytes = BUFF_LEN + (*tmp)->extra;
		return (1);
	}
	return (0);
}
