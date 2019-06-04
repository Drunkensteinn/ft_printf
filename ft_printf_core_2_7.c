/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_2_7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:25:02 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/30 18:25:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			pre_output_2_1(t_alist **tmp, size_t l2, char *symbol)
{
	if (l2 < BUFF_SIZE || (*tmp)->size_bytes >= BUFF_SIZE)
	{
		output((*tmp)->fd, (*tmp)->buff, BUFF_SIZE);
		ft_bzero((*tmp)->buff, BUFF_SIZE);
		(*tmp)->extra3 = (*tmp)->size_bytes;
		(*tmp)->size_bytes = 0;
		ft_memcpy((*tmp)->buff, symbol, l2);
		(*tmp)->size_bytes = l2;
		return (1);
	}
	(*tmp)->size_bytes += (*tmp)->extra3;
	return (0);
}

inline void			pre_output_2_2(t_alist **tmp, char *symbol)
{
	ft_memcpy(&(*tmp)->buff[(*tmp)->size_bytes], symbol, BUFF_SIZE);
	output((*tmp)->fd, (*tmp)->buff, BUFF_SIZE - 1);
	ft_bzero((*tmp)->buff, BUFF_SIZE);
}
