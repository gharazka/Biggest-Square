/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:10:47 by gharazka          #+#    #+#             */
/*   Updated: 2023/09/27 23:41:11 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"


void	find_square_len(t_map map, int **int_map, int dec_wid, int dec_len)
{
	int	i;

	i = 0;
	while (i <= dec_wid)
	{
		if (int_map[dec_len][dec_wid- i] == 0 && map.arr[dec_len][dec_wid - i] != map.obstacle)
		{
			if(int_map[dec_len][dec_wid - i + 1] == int_map[dec_len + 1][dec_wid - i + 1]
			&& int_map[dec_len][dec_wid - i + 1] == int_map[dec_len + 1][dec_wid - i])
				int_map[dec_len][dec_wid - i] = int_map[dec_len][dec_wid - i + 1] + 1;
			else if(int_map[dec_len][dec_wid - i + 1]
			< int_map[dec_len + 1][dec_wid - i + 1] 
			&& int_map[dec_len][dec_wid - i + 1] < int_map[dec_len + 1][dec_wid - i])
				int_map[dec_len][dec_wid - i] = int_map[dec_len][dec_wid - i + 1] + 1;
			else if(int_map[dec_len + 1][dec_wid - i + 1]
				       	< int_map[dec_len + 1][dec_wid - i])
				int_map[dec_len][dec_wid - i]
				       	= int_map[dec_len + 1][dec_wid - i + 1] + 1;
			else
				int_map[dec_len][dec_wid - i] = int_map[dec_len + 1][dec_wid - i] + 1;
		}
		i++;
	}
}

void	find_square_wid(t_map map, int **ip, int dec_w, int dec_l)
{
	int i;

	i = 0;
	while (i <= dec_l)
	{
		if (ip[dec_l - i][dec_w] == 0 && map.arr[dec_l - i][dec_w] != map.obstacle)
		{
			if(ip[dec_l - i][dec_w + 1] == ip[dec_l - i + 1][dec_w + 1]
				       	&& ip[dec_l - i][dec_w + 1]
				       	== ip[dec_l - i + 1][dec_w])
				ip[dec_l - i][dec_w] = ip[dec_l - i][dec_w + 1] + 1;
			else if(ip[dec_l - i][dec_w + 1]
				       	< ip[dec_l - i + 1][dec_w + 1]
			&& ip[dec_l - i][dec_w + 1] < ip[dec_l - i + 1][dec_w])
				ip[dec_l - i][dec_w] = ip[dec_l - i][dec_w + 1] + 1;
			else if(ip[dec_l - i + 1][dec_w + 1]
				       	< ip[dec_l - i + 1][dec_w])
				ip[dec_l - i][dec_w]
				       	= ip[dec_l - i + 1][dec_w + 1] + 1;
			else
				ip[dec_l - i][dec_w] = ip[dec_l - i + 1][dec_w] + 1;
		}
		i++;
	}
}

void	find_biggest_square(t_map map, int **int_map, int dec_wid, int dec_len)
{
	if (dec_len < 0 || dec_wid < 0)
	{
		return ;
	}
	find_square_wid(map, int_map, dec_wid, dec_len);
	find_square_len(map, int_map, dec_wid, dec_len);
	find_biggest_square(map, int_map, dec_wid - 1, dec_len - 1);
}

void	fill_last_square(t_map map, int **int_map)
{
	int	i;
	int	dec_len;
	int	dec_wid;

	i = 0;
	dec_len = map.length - 1;
	dec_wid = map.width - 1;
	while (i <= dec_wid)
	{
		if (map.arr[dec_len][dec_wid - i] == map.obstacle)
			int_map[dec_len][dec_wid - i] = 0;
		else
			int_map[dec_len][dec_wid - i] = 1;
		i++;
	}
	i = 0;
	while (i <= dec_len)
	{
		if (map.arr[dec_len - i][dec_wid] == map.obstacle)
			int_map[dec_len - i][dec_wid] = 0;
		else
			int_map[dec_len - i][dec_wid] = 1;
		i++;
	}
}

void	fill_map_with_zeros(int **int_map, int width, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < width)
		{
			int_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**create_int_map(int width, int length)
{
	int	**int_map;

	int_map = malloc(sizeof(int *) * length);
	for (int i = 0; i < length; i++)
	{
		int_map[i] = malloc(sizeof(int) * width);
	}
	fill_map_with_zeros(int_map, width, length);
	return (int_map);
}

void	fill_map(t_map map, int **int_map)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;
	int	max_square;

	max_i = 0;
	max_j = 0;
	i = 0;
	while (i < map.length - 1)
	{
		j = 0;
		while (j < map.width - 1)
		{
			if (int_map[i][j] > int_map[max_i][max_j])
			{
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	max_square = int_map[max_i][max_j];
	i = max_i;
	max_i = 0;
	while (max_square - max_i > 0)
	{
		j = max_j;
		while (j != max_j + max_square)
		{
			map.arr[i][j] = map.full;
			j++;
		}
		i++;
		max_i++;
	}
}

void	helper(t_map map)
{
	int	**int_map; 
		
	int_map = create_int_map(map.width, map.length);
	fill_last_square(map, int_map);
	find_biggest_square(map, int_map, map.width - 2, map.length - 2);
	fill_map(map, int_map);
	for (int i = 0; i < map.length; i++)
	{
		for (int j = 0; j < map.width; j++)
		{
			printf("%c", map.arr[i][j]);
		}
		printf("\n");
		free(int_map[i]);
	}
	free(int_map);
}
