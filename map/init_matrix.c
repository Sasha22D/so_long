#include "so_long.h"

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
	matrix = malloc(sizeof(char *) * (line_count + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		matrix[i] = malloc(sizeof(char) * (length + 1));
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
		free(line);
		i++;
	}
	close(fd);
}

// int	main()
// {
// 	int	fd;
// 	char	**map;

// 	fd = open("map.ber", O_RDONLY);
// 	map = init_matrix(fd);
// 	fill_matrix(map);
// 	destroy_map(map);
// 	close(fd);
// }