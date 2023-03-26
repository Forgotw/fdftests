/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:22:52 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/03/06 18:07:28 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>

//#include "libft.h"
//#include "mlx.h"
#include "../gnl/get_next_line.h"

typedef	struct	s_data
{
	int	**matrix;
	int	map_x;
	int	map_y;
}				fdf_data;

char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);

#endif
