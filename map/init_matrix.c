#include "so_long.h"

static int	count_line_and_length(int fd, int *length)
{
	int		line_count;
	int		error;
	char	*line;

	line_count = 0;
	error = 0;
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		if (line_count == 0)
			*length = lenstr(line);
		else
		{
			if (*length != lenstr(line))
				error = -1;
		}
		line_count++;
		free(line);
		line = NULL;
	}
	if (error == -1)
		return (-1);
	return (line_count);
}

char	**init_matrix(int fd, t_game *gameStruct)
{
	int	length;
	int	line_count;
	int	i;
	char	**matrix;

	length = 0;
	line_count = count_line_and_length(fd, &length);
	if (line_count == -1)
		return (NULL);
	matrix = malloc(sizeof(char *) * (line_count + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		matrix[i] = malloc(sizeof(char) * (length + 1));
		if (!matrix[i])
			return (destroy_map(matrix), NULL);
		i++;
	}
	matrix[i] = NULL;
	gameStruct->length = line_count;
	gameStruct->width = length;
	return (matrix);
}

void	fill_matrix(char **map)
{
	int	fd;
	int	i;
	int	j;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return ;
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
		map[i][j - 1] = '\0';
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
}
