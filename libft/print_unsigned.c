/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:16:35 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned int n, int count)
{
	if (n <= 9)
		count += print_char(n + '0');
	else
	{
		count = print_dec(n / 10, count);
		count += print_char(n % 10 + '0');
	}
	return (count);
}
