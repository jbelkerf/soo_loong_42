/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:43 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/01 13:31:45 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the lstnew take a void content and put it in a new node and return thr node
 */
t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(1 * sizeof(t_stack));
	if (new == 0)
		return (0);
	new->value = value;
	new->next = NULL;
	return (new);
}
