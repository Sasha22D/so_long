#include <stdio.h>
#include <fcntl.h>
#include "get_net_line_try1/get_next_line.h"

int	lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	**init_matrix(int fd)
{
	int	length;
	int	line_count;
	int	i;
	char	*line;
	char	**matrix;

	line = NULL;
	length = 0;
	line_count = 0;
	while ((line = get_next_line(fd)))
	{
		length = lenstr(line);
		line_count++;
		free(line);
	}
	if (line)
		free(line);
	matrix = malloc(sizeof(char *) * line_count);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		matrix[i] = malloc(sizeof(char) * length);
		if (!matrix[i])
		{
			while (i >= 0)
				free(matrix[i--]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	fill_matrix(char **map)
{
	int	fd;
	int	i;
	int	j;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	i = 0;
	while (map[i])
	{
		line = get_next_line(fd);
		j = 0;
		while (line[j])
		{
			if (line[j] != '\n')
				map[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	if (line)
		free(line);
	close(fd);
}

int	main()
{
	int	fd;
	char	**map;

	fd = open("map.ber", O_RDONLY);
	map = init_matrix(fd);
	fill_matrix(map);
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	free(map);
	close(fd);
}