/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:06:01 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/28 13:46:34 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!new)
		return ;
	if (!*alst)
		*alst = new;
	else if (!(*alst)->next)
		(*alst)->next = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
