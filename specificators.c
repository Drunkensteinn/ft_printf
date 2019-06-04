/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:04:00 by ablizniu          #+#    #+#             */
/*   Updated: 2018/04/21 19:23:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			presic_(t_alist **tmp)
{
	if (g_flags & presicions)
		return (0);
	if (*(*tmp)->str == '.')
	{
		(*tmp)->str++;
		(*tmp)->k = (size_t)ft_atoi((*tmp)->str);
		while (*(*tmp)->str >= '0' && *(*tmp)->str <= '9')
			(*tmp)->str++;
		g_flags |= presicions;
		return (1);
	}
	return (0);
}

int			validator_flags(t_alist **tmp)
{
	if (validator_flags_0(tmp))
		return (1);
	if (validator_flags_1(tmp))
		return (1);
	if (validator_flags_2(tmp))
		return (1);
	return (0);
}

int			validator_flags_0(t_alist **tmp)
{
	if (*(*tmp)->str == 'h' && *((*tmp)->str + 1) == 'h')
	{
		if (!g_flags)
			g_flags = g_flags | hh;
		else if (g_flags < hh)
			g_flags |= hh;
		(*tmp)->str += 2;
		return (1);
	}
	else if (*(*tmp)->str == 'h')
	{
		if (!g_flags)
			g_flags = g_flags | h;
		else if (g_flags < h)
		{
			g_flags ^= search();
			g_flags |= h;
		}
		(*tmp)->str++;
		return (1);
	}
	return (0);
}

int			validator_flags_1(t_alist **tmp)
{
	if (*(*tmp)->str == 'l' && *((*tmp)->str + 1) == 'l')
	{
		if (!g_flags)
			g_flags = g_flags | ll;
		else if (g_flags < ll)
		{
			g_flags ^= search();
			g_flags |= ll;
		}
		(*tmp)->str += 2;
		return (1);
	}
	else if (*(*tmp)->str == 'l')
	{
		if (!g_flags)
			g_flags = g_flags | l;
		else if (g_flags < l)
		{
			g_flags ^= search();
			g_flags |= l;
		}
		(*tmp)->str++;
		return (1);
	}
	return (0);
}

int			validator_flags_2(t_alist **tmp)
{
	if (*(*tmp)->str == 'j')
	{
		if (!g_flags)
			g_flags = g_flags | j;
		if (g_flags < j)
		{
			g_flags ^= search();
			g_flags |= j;
		}
		(*tmp)->str++;
		return (1);
	}
	else if (*(*tmp)->str == 'z')
	{
		if (!g_flags)
			g_flags = g_flags | z;
		else if (g_flags < z)
		{
			g_flags ^= search();
			g_flags |= z;
		}
		(*tmp)->str++;
		return (1);
	}
	return (0);
}
