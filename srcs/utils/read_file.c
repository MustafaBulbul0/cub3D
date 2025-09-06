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
	all->game->map = special_split(buf);
	if (!all->game->map)
		exit_print("Empty map.", all);
	free(buf);
}

void	read_map(t_all *all, char *path)
{
	int		i;
	int		j;
	int		k;
	char	**map;

	k = 0;
	i = 0;
	j = 0;
	clear_2d_pointer(all->game->map);
	read_and_split(path, all);
	map = strdup_2d(all->game->map);
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
	clear_2d_pointer(all->game->map);
	all->game->map = strdup_2d(map + i + 1);
	clear_2d_pointer (map);
}
