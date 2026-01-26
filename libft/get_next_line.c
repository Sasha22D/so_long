/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:17:38 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 17:17:40 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_free(char **ptr_buffer, char **ptr_stash)
{
	free(*ptr_buffer);
	*ptr_buffer = NULL;
	free(*ptr_stash);
	*ptr_stash = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	int			bytes;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = NULL;
	while (!ft_is_newline(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (ft_free(&buffer, &stash), NULL);
		buffer[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	line = ft_putline(line, stash);
	ft_clean_stash(&stash);
	return (free(buffer), buffer = NULL, line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int	fd;
// 	fd = open("file.txt", O_RDONLY);
// 	// printf("fd = %d\n", fd);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // affiche la ligne avec le \n s'il existe
// 		free(line);
// 	}
// 	close(fd);
// }