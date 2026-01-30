/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:57:07 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/30 11:57:09 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	arg_checker(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 4), ".ber", 4) != 0)
		return (-1);
	return (0);
}
