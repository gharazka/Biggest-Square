/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:21:51 by gharazka          #+#    #+#             */
/*   Updated: 2023/09/27 23:30:17 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	display_error(void)
{
	write(2, "map error\n", 10);
}

int	main_loop(char *file_str, int i, int map_count)
{
	t_map	map;

	if (check_file_errors(file_str))
	{
		display_error();
		map_count++;
		return (map_count + 1);
	}
	map = get_map_struct(file_str);
	if (check_map_errors(map))
	{
		display_error();
		map_count++;
		return (map_count + 1);
	}
	helper(map);
	while (i < map.length)
	{
		free(map.arr[i]);
		i++;
	}
	free(map.arr);
	return (map_count + 1);
}

int	main(int argc, char *argv[])
{
	char	*file_str;
	int		i;
	int		map_count;

	map_count = 1;
	while (map_count < argc)
	{
		i = 0;
		file_str = file_to_str(argv[map_count]);
		main_loop(file_str, i, map_count);
		free(file_str);
		map_count++;
	}
	exit(0);
}
