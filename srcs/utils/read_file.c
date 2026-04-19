/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:19:56 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 14:32:54 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*ft_read(int fd)
{
	int		ret;
	int		i;
	char	c;
	char	*buf;

	i = 0;
	buf = ft_calloc(1, sizeof(char));
	if (!buf)
		return (NULL);
	ret = read(fd, &c, 1);
	while (ret > 0)
	{
		buf = ft_realloc(buf, i + 1);
		if (!buf)
			return (NULL);
		buf[i] = c;
		ret = read(fd, &c, 1);
		i++;
	}
	return (buf);
}

void	read_and_split(char *path, t_all *all)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_print("The file could not be opened.", all);
	buf = ft_read(fd);
	if (close(fd) == -1)
		exit_print("File close failed.", all);
	if (!buf)
		exit_print("Map read failed.", all);
	all->game->map = special_split(buf);
	if (!all->game->map)
	{
		free(buf);
		exit_print("Empty map.", all);
	}
	free(buf);
}

static int	find_start_index(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((9 > map[i][j] || map[i][j] > 13) && map[i][j] != 32)
			{
				k++;
				break ;
			}
			j++;
		}
		if (k == 6)
			break ;
		i++;
	}
	if (k < 6)
		return (-1);
	return (i);
}

static char	**end_map(char **map, int i, int space)
{
	char	**n_map;

	n_map = calloc(1, sizeof(char *));
	if (!n_map)
		return (NULL);
	while (map[++i])
	{
		n_map = ft_realloc_2d(n_map, (space + 2) * sizeof(char *));
		if (!n_map)
			return (NULL);
		n_map[space] = ft_strdup(map[i]);
		n_map[++space] = NULL;
	}
	return (n_map);
}

void	read_map(t_all *all, char *path)
{
	int		start_index;
	char	**map;

	clear_2d_pointer(all->game->map);
	read_and_split(path, all);
	map = strdup_2d(all->game->map);
	start_index = find_start_index(map);
	clear_2d_pointer(all->game->map);
	all->game->map = end_map(map, start_index, 0);
	clear_2d_pointer(map);
}
