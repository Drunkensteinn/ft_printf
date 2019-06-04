/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponentiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:51:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/03/26 20:51:18 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_exponentiation(int num, int exp)
{
	int		res;

	res = 0;
	if (exp == 0)
		return (1);
	while (exp)
	{
		res = res * num;
		exp--;
	}
	return (res);
}
