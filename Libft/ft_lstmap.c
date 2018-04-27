/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:01:34 by theogell          #+#    #+#             */
/*   Updated: 2018/04/21 16:14:21 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (start)
		{
			current->next = new;
			current = current->next;
		}
		else
		{
			start = new;
			current = start;
		}
		lst = lst->next;
	}
	return (start);
}
