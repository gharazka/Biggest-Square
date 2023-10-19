#include "ft_func.h"

char	**get_map(char *file_str, int i, int map_length)
{
	int		count;
	int		j;
	char	**map_arr;

	count = 0;
	map_arr = (char **)malloc(sizeof(char *) * map_length + 1);
	while (count < map_length)
	{
		map_arr[count] = (char *)malloc(1 * (get_map_width(file_str, i) + 1));
		j = 0;
		if (file_str[i] != '\n' && file_str[i] != 0)
		{
			while (file_str[i] != '\n' && file_str[i] != 0)
			{
				map_arr[count][j] = file_str[i];
				j++;
				i++;
			}
			map_arr[count][j] = 0;
			count++;
		}
		else
			i++;
	}
	return (map_arr);
}

char	*get_map_length(char *file_str)
{
	int		i;
	char	*map_length;

	i = 0;
	while (file_str[i + 4] != '\n')
	{
		i++;
	}
	map_length = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (file_str[i + 4] != '\n')
	{
		map_length[i] = file_str[i];
		i++;
	}
	map_length[i] = 0;
	return (map_length);
}

t_map	get_map_struct(char *file_str)
{
	int		i;
	t_map	map;

	i = 0;
	while (file_str[i] != '\n')
	{
		i++;
	}
	map.full = file_str[i - 1];
	map.obstacle = file_str[i - 2];
	map.empty = file_str[i - 3];
	map.length = ft_atoi(get_map_length(file_str));
	map.width = get_map_width(file_str, i);
	map.arr = get_map(file_str, i, map.length);
	return (map);
}
