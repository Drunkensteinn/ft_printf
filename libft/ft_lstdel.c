/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:50:28 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:27:18 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*buffer;

	buffer = NULL;
	while (*alst || buffer)
	{
		if (buffer)
			*alst = buffer;
		del((*alst)->content, (*alst)->content_size);
		buffer = (*alst)->next;
		free(*alst);
		*alst = NULL;
	}
}
