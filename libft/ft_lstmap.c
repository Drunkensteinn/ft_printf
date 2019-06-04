/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:23:15 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/06 17:40:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*buffer;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	buffer = tmp;
	lst = lst->next;
	while (lst != NULL)
	{
		buffer->next = f(lst);
		buffer = buffer->next;
		lst = lst->next;
	}
	return (tmp);
}
