/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:07:40 by gharazka          #+#    #+#             */
/*   Updated: 2023/09/27 23:40:35 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	check_char(t_map map)
{
	if (map.full == map.empty || map.full == map.obstacle)
		return (1);
	if (map.empty == map.obstacle)
		return (1);
	if (map.length == 0)
		return (1);
	return (0);
}

int	check_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.length)
	{
		j = 0;
		while (j < map.width)
		{
			if ((map.arr[i][j] != map.empty && map.arr[i][j] != map.obstacle))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_errors(t_map map)
{
	if (check_char(map))
		return (1);
	if (check_map(map))
		return (1);
	return (0);
}
