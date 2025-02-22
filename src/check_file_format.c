/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:51:50 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 17:52:32 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_the_file_extention(char *file)
{
	int	name_lenght;

	name_lenght = ft_strlen(file);
	if (name_lenght <= 4)
		puts_error("file name not correct");
	if (file[name_lenght - 1] != 'r' || file[name_lenght - 2] != 'e')
		puts_error("file name not correct");
	if (file[name_lenght - 3] != 'b' || file[name_lenght - 4] != '.')
		puts_error("file name not correct");
	if (file[name_lenght - 5] == '/')
		puts_error("file name not correct");
}

void	check_the_file_readablity(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		puts_error("file not exist or not readable");
	close (fd);
}

void	check_the_file(char *file)
{
	check_the_file_extention(file);
	check_the_file_readablity(file);
}
