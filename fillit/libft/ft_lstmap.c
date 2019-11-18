/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:00:39 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 12:04:19 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = NULL;
	while (lst)
	{
		ft_lstaddend(&new_lst, f(lst));
		tmp = new_lst;
		lst = lst->next;
	}
	return (new_lst);
}
