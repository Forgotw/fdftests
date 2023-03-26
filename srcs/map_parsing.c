/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:22:38 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/03/26 14:50:03 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_to_tab(char *file, fdf_data *data)
{
	char	*line;
	char	**array;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		array = ft_split(line, ' ');
		while (array[i])
		{
			data->map_x += 1;
			data->matrix[data->map_y][i] = ft_atoi(array[i]);
			i++;
		}
		data->map_y += 1;
		i = 0;
		free(array);
		free(line);
		line = get_next_line(fd);
	}
	data->map_x /= data->map_y;
	return (close(fd), 1);
}