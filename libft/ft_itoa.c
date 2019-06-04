/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:40:57 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/04 20:25:32 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char *str)
{
	int			j;
	size_t		len;
	char		c;

	j = 0;
	len = ft_strlen(str) - 1;
	while ((int)len > j)
	{
		c = str[j];
		str[j] = str[len];
		str[len] = c;
		len--;
		j++;
	}
}

static int		lenght_1(int n)
{
	int			i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

const char		*fill_str(int j, int *i)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * lenght_1(j) + 1);
	if (str == NULL)
		return (NULL);
	while (j > 0)
	{
		str[*i] = j % 10 + 48;
		j = j / 10;
		*i += 1;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	j;
	long int	sign;

	i = 0;
	sign = 0;
	if (n == 0)
		return (ft_strdup("0\0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	j = (long int)n;
	if (j < 0)
	{
		sign = j;
		j *= -1;
	}
	str = (char *)fill_str(j, &i);
	if (str == NULL)
		return (NULL);
	if (sign < 0)
		str[i++] = '-';
	str[i++] = '\0';
	ft_swap(str);
	return (str);
}
