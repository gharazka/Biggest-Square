#include "ft_func.h"

char	*file_to_str(char *file_name)
{
	char	*file_str;
	int		fd;
	int		sz;

	file_str = (char *)malloc(sizeof(char) * 1000000);
	fd = open(file_name, O_RDONLY);
	sz = read(fd, file_str, 1000000);
	file_str[sz] = 0;
	close(fd);
	return (file_str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != 0)
	{
		result += str[i] - '0';
		result *= 10;
		i++;
	}
	result /= 10;
	free(str);
	return (result);
}

int	get_map_width(char *file_str, int i)
{
	int	j;

	j = 0;
	i++;
	while (file_str[i] != '\n')
	{
		i++;
		j++;
	}
	return (j);
}
