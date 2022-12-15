/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:15:39 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/08 22:32:16 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!del || !lst || !(*lst))
		return ;
	while (*lst && lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = aux;
	}
}
