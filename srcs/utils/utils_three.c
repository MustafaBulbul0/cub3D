/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:46:14 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 12:46:15 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

void	flood_fill(char **map, int xz[2], int row, int col)
{
	int	new_xz[2];

	if (xz[0] < 0 || xz[1] < 0 || xz[0] >= row || xz[1] >= col)
		return ;
	if (!is_space(map[xz[0]][xz[1]]))
		return ;
	map[xz[0]][xz[1]] = 'F';
	new_xz[0] = xz[0] + 1;
	new_xz[1] = xz[1];
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0] - 1;
	new_xz[1] = xz[1];
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0];
	new_xz[1] = xz[1] + 1;
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0];
	new_xz[1] = xz[1] - 1;
	flood_fill(map, new_xz, row, col);
}

int	secret_file(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	while (i >= 0)
	{
		if (path[i] == '/')
			break ;
		i--;
	}
	if (path[i + 1] == '.')
		return (1);
	return (0);
}

char	**ft_realloc_2d(char **ptr, size_t size)
{
	char	**new_ptr;
	size_t	i;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		i = 0;
		while (ptr[i])
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (new_ptr);
}

int	close_windows(t_all *all)
{
	ft_free_all(all);
	exit(0);
}

int	character_control(char c, t_all *all)
{
	int	position;

	position = 0;
	if (!(c == '1' || c == '0' || is_space(c) || c == 'N'
			|| c == 'S' || c == 'E' || c == 'W' || c == '\0'))
		exit_print("The map is wrong.", all);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		position++;
	return (position);
}
