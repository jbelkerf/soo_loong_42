/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/01 13:54:13 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_p(char **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
	return (NULL);
}

int	ftt_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ftt_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ftt_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ftt_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s1 == NULL)
		return (NULL);
	re = (char *)malloc((ftt_strlen(s1) + ftt_strlen(s2) + 1) * sizeof(char));
	if (re == NULL)
		return (free(s1), NULL);
	while (s1[++j])
		re[j] = s1[j];
	while (s2[++i])
		re[j + i] = s2[i];
	return (re[j + i] = 0, free(s1), s1 = NULL, re);
}
