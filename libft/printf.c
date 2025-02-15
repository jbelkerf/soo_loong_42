/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:01:35 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	char	*tmp;
	char	*dup;
	int		count;
	va_list	ap;

	dup = ft_strdup(str);
	tmp = dup;
	count = 0;
	i = 0;
	va_start(ap, str);
	i = 0;
	while (dup[i])
	{
		if (dup[i] == '%')
			count += check_flag(dup[++i], ap);
		else
			count += print_char(dup[i]);
		i++;
	}
	free(tmp);
	return (count);
}
