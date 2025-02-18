#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int count_line(char *file)
{
	int fd;
	int line_count;
	char *str;

	fd = open(file, O_RDONLY);
	line_count = 0;
	while (1)
	{
		if ((str = get_next_line(fd)) == NULL)
			break ;
		line_count++;
		free(str);
	}
	close(fd);
	return (line_count);
}

char **map_to_str(char *file)
{
	int fd;
	char *line;
	char **re;
	int i;

	re = malloc((count_line(file) + 1) * sizeof(char *));
	i = 0;
	while (1)
	{
		if ((line = get_next_line(fd)) == NULL)
        printf("line == %s\n", line);
			break ;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		re[i] = line;
		i++;
	}
	re[i] = NULL;
	return (re);
}

int main(int argc, char **argv)
{
    char **re = map_to_str(argv[1]);
    int i = 0;

    while (i < 5)
    {
        printf("%s\n", re[i]);
        i++;
    }
}
