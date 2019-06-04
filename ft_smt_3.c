/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smt_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:57:01 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/28 15:57:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void		p_h_1(t_alist **tmp, char *str, size_t l, int *ret)
{
	hash_and_presic_o_o(tmp, l, &str[0]);
	*ret += 1;
}

inline void		p_h_2(t_alist **tmp, char *str, size_t l, int *ret)
{
	hash_and_presic_x_x(tmp, l, &str[0]);
	*ret += 1;
}

inline void		p_h_3(t_alist **tmp, char *str, size_t l, int *ret)
{
	pointer_addres(tmp, l, str);
	*ret += 1;
}

inline void		p_h_4(char *s)
{
	((g_flags & hash) && (g_flags & X)) ? ((s[0] = '0')) : (0);
	((g_flags & hash) && (g_flags & X)) ? ((s[1] = 'X')) : (0);
	((g_flags & hash) && (g_flags & x)) ? ((s[0] = '0')) : (0);
	((g_flags & hash) && (g_flags & x)) ? ((s[1] = 'x')) : (0);
}

inline void		p_h_5(char *s)
{
	(g_flags & X) ? ((s[0] = '0')) : (0);
	(g_flags & X) ? ((s[1] = 'X')) : (0);
	(g_flags & x) ? ((s[0] = '0')) : (0);
	(g_flags & x) ? ((s[1] = 'x')) : (0);
}
