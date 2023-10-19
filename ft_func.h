#ifndef FT_FUNC_H
# define FT_FUNC_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //to delete at the end//

typedef struct map_info
{
	char	full;
	char	empty;
	char	obstacle;
	int		length;
	int		width;
	char	**arr;
}t_map;

char	*file_to_str(char *file_name);
int	ft_atoi(char *str);
int	get_map_width(char *file_str, int i);
void	helper(t_map map);
char	*file_to_str(char *file_name);
t_map	get_map_struct(char *file_str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int	check_file_errors(char *file_str);
int	check_map_errors(t_map map);

#endif
