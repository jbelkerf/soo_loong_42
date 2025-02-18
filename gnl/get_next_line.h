/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:41:44 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 17:58:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strdup(const char *s);
void	*free_p(char **p);
char	*get_next_line(int fd);
char	*ftt_strjoin(char *s1, char *s2);
int		ftt_strlen(const char *str);
char	*ftt_substr(char *s, unsigned int start, size_t len);

#endif
