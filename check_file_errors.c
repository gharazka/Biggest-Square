/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:21:14 by gharazka          #+#    #+#             */
/*   Updated: 2023/09/27 23:27:21 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	compare_lines(char *file_str, int index, int last_len, int line_len)
{
	while (file_str[index])
	{
		if (file_str[index] == '\n')
		{
			if (last_len != line_len)
				return (1);
			last_len = line_len;
			line_len = 0;
			index++;
		}
		index++;
		line_len++;
	}
	return (0);
}

int	check_all_lines(char *file_str)
{
	int	i;
	int	line_length;
	int	last_line_len;

	i = 0;
	last_line_len = 0;
	line_length = 0;
	while (file_str[i] && file_str[i - 1] != '\n')
		i++;
	while (file_str[i] && file_str[i] != '\n')
	{
		last_line_len++;
		i++;
	}
	i++;
	if (compare_lines(file_str, i, last_line_len, line_length))
		return (1);
	return (0);
}

int	empty_map(char *file_str)
{
	int	i;

	i = 0;
	if (file_str[i] == 0)
		return (1);
	while (file_str[i] != '\n')
		i++;
	if (file_str[i + 1] == 0)
		return (1);
	return (0);
}

int	check_file_errors(char *file_str)
{
	if (check_all_lines(file_str))
		return (1);
	if (empty_map(file_str))
		return (1);
	return (0);
}
