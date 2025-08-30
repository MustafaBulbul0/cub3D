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
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("The file could not be opened: %s\n", strerror(errno));
		exit(errno);
	}
	buf = ft_read(fd);
	map = ft_split(buf, '\n');
	free(buf);
	return (map);
}
