/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:57 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	hexa_l(long pp, int c)
{
	char	*base;

	base = "0123456789abcdef";
	if (pp >= 0 && pp <= 15)
	{
		write(1, &base[pp], 1);
		c++;
	}
	else
	{
		c += hexa_l(pp / 16, c);
		write(1, &base[pp % 16], 1);
		c++;
	}
	return (c);
}
