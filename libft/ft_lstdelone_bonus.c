/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:14 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:55 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the lstdelone take a node and a del func used to delete the content and then
 * free the node
 */
void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		free(lst);
	}
}
