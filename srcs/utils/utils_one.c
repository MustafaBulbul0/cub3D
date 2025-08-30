#include "../../librarys/cub3d.h"

static char	*ft_realloc(char *s, int size)
{
	char	*new_s;
	int		i;

	if (size == 0)
		return (free(s), NULL);
	new_s = ft_calloc(size + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		new_s[i] = s[i];
		i++;
	}
	free(s);
	return (new_s);
}

char	**read_and_split(char *path)
{
	int		ret;
	int		i;
	int		fd;
	char	*buf;
	char	c;
	char	**map;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("The file could not be opened: %s\n",
			strerror(errno));
		exit(errno);
	}
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
	map = ft_split(buf, '\n');
	free(buf);
	return (map);
}

void	clear_2d_pointer(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
