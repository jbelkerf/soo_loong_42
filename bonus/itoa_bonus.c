/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:32:03 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/24 11:49:57 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_is_negative(long *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (1);
	}
	return (0);
}

int	count_the_len(long n, int is_negative)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	if (is_negative)
		len = len + 3;
	else
		len = len + 2;
	return (len);
}

char	*str_rev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str);
	len--;
	while (i <= len / 2)
	{
		c = str[i];
		str[i] = str[len - i];
		str[len - i] = c;
		i++;
	}
	return (str);
}

void	set_the_string(int is_negative, long n, char **res)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		(*res)[i] = (n % 10) + '0';
		i++;
		n = n / 10;
	}
	(*res)[i] = n + '0';
	i++;
	if (is_negative)
	{
		(*res)[i] = '-';
		i++;
	}
	(*res)[i] = '\0';
	*res = str_rev(*res);
}

char	*itoa(int nbr)
{
	char	*res;
	long	n;
	int		is_negtive;
	int		len;

	n = nbr;
	is_negtive = check_is_negative(&n);
	len = count_the_len(n, is_negtive);
	res = malloc(len * sizeof(char));
	set_the_string(is_negtive, n, &res);
	return (res);
}
