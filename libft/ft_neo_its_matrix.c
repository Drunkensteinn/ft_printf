/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neo_its_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:17:46 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 19:24:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_neo_its_matrix(int column, int raw)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (column + 1));
	while (i < column)
		str[i++] = (char *)malloc(sizeof(char) * (raw + 1));
	while (i < column)
	{
		while (j < raw)
		{
			str[i][j] = '0';
			j++;
		}
		str[i][j] = '\0';
		i++;
		j = 0;
	}
	str[i] = NULL;
	return (str);
}
