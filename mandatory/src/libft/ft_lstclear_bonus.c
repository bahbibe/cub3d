/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:29:06 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 12:57:56 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*last;

	if (!lst || !del || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		last = current;
		del(current->content);
		current = current->next;
		free(last);
	}
	*lst = NULL;
}
