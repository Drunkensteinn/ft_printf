/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:55:25 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/04 14:36:56 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist		*ft_alist_initialize(t_alist *head, size_t bytes)
{
	if (head == NULL)
	{
		head = (t_alist *)malloc(sizeof(t_alist));
		head->next = NULL;
		head->str = NULL;
		head->prev = NULL;
		head->tmp_1 = NULL;
		head->j = 0;
		head->i = 0;
		head->fd = 0;
		head->list = NULL;
		head->size_bytes = bytes;
		ft_bzero(head->buff, bytes);
		return (head);
	}
	head->next = (t_alist *)malloc(sizeof(t_alist));
	head->next->prev = head;
	while (head->next)
		head = head->next;
	head->list = NULL;
	head->size_bytes = bytes;
	ft_bzero(head->buff, bytes);
	head->next = NULL;
	return (head);
}
