#include "../../includes/cub3d.h"

char	*new_row(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_s = ft_calloc (1, sizeof(char));
	while (s[i])
	{
		if (s[i] != 9 && (11 > s[i] || s[i] > 13) && s[i] != 32 )
		{
			new_s = ft_realloc(new_s, j + 2);
			new_s[j] = s[i];
			j++;
		}
		i++;
	}
	free (s);
	return (new_s);
}

char	**trim_map(char **map, int i)
{
	int		j;
	int		len;
	char	**n_map;

	j = 0;
	len = 0;
	if(map[len])
		len++;
	n_map = ft_calloc(len, sizeof(char *));
	len = 0;
	while (map[j])
	{
		if (i == j)
		{
			j++;
			continue ;
		}
		n_map[len] = ft_strdup(map[j]);
		j++;
		len++;
	}
	clear_2d_pointer(map);
	return (n_map);
}

char	**file_edit(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		map[i] = new_row(map[i]);
		if (map[i][0] == '\n')
			map = trim_map (map, i);
		i++;
	}
	return (map);
}

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
	{
		printf("The file could not be opened: %s\n", strerror(errno));
		exit(errno);
	}
	buf = ft_read(fd);
	all->game->map = file_edit(ft_split(buf, '\n'));
	init_map_texture(all);
	free(buf);
}
