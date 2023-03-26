/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:37:29 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/03/26 14:49:13 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			x++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (x);
}

char	*ft_worddup(char const *s, int len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_splitword(char **array, char const *s, char c)
{
	int	i;
	int	x;
	int	a;

	i = 0;
	x = 0;
	a = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i + x] != '\0' && s[i + x] != c)
			x++;
		if (x > 0)
		{
			array[a++] = ft_worddup(&s[i], x);
			i = i + x;
			x = 0;
		}
	}
	array[a] = NULL;
}

char	**ft_split(char *s, char c)
{
	int		x;
	char	**array;

	if (!s)
		return (NULL);
	x = ft_count(s, c);
	array = malloc(sizeof(char *) * (x + 1));
	if (!array)
		return (NULL);
	ft_splitword(array, s, c);
	return (array);
}