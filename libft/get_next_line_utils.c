/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:17:51 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 17:17:52 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlen_gnl(char *s)
{
	int	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	char	*p;
	char	*tmp_s1;

	if (!s2 || !*s2)
		return (NULL);
	tmp_s1 = s1;
	str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (NULL);
	p = str;
	if (s1)
	{
		while (*tmp_s1)
			*p++ = *tmp_s1++;
	}
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_putline(char *str, char *stash)
{
	char	*new;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	new = malloc(i + (stash[i] == '\n') + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	free(str);
	str = NULL;
	return (new);
}

void	ft_clean_stash(char **stash)
{
	char	*str;
	char	*new;
	int		i;

	i = 0;
	if (!*stash || !stash)
		return ;
	str = *stash;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	else
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	new = ft_strjoin_gnl(NULL, str + i);
	free(*stash);
	*stash = new;
	str = NULL;
	return ;
}
