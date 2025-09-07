#include "../../includes/cub3d.h"

char	*new_row(char *s)
{
	char	*new_s;
	char	*old_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	old_s = s;
	new_s = ft_calloc(1, sizeof(char));
	while (s[i])
	{
		if (!is_space(s[i]))
		{
			new_s = ft_realloc(new_s, j + 2);
			new_s[j++] = s[i];
			new_s[j] = '\0';
		}
		i++;
	}
	free(old_s);
	return (new_s);
}

char	**trim_map(char **map, int i)
{
	int		j;
	int		len;
	char	**n_map;

	len = 0;
	while (map[len])
		len++;
	n_map = ft_calloc(len, sizeof(char *));
	j = 0;
	len = 0;
	while (map[j])
	{
		if (i == j)
		{
			j++;
			continue ;
		}
		n_map[len++] = ft_strdup(map[j]);
		j++;
	}
	clear_2d_pointer(map);
	return (n_map);
}

char	**file_edit(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		map[i] = new_row(map[i]);
		if (map[i][0] == '\0')
		{
			map = trim_map(map, i);
			i = 0;
		}
		else
			i++;
	}
	return (map);
}

void	init_map_color(t_all *all)
{
	int		i;
	int		j;
	char	*f;
	char	*c;

	f = all->texture->f;
	c = all->texture->c;
	if (!f || !c)
		return ;
	i = 0;
	j = 0;
	while (f[i])
	{
		all->texture->f_color[j] = ft_atoi(&f[i]);
		while (f[i] != ',' && f[i])
			i++;
		if (f[i])
			i++;
		j++;
	}
	j = 0;
	i = 0;
	while (c[i])
	{
		all->texture->c_color[j] = ft_atoi(&c[i]);
		while (c[i] != ',' && c[i])
			i++;
		if (c[i])
			i++;
		j++;
	}
}

void	init_map_texture(t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = strdup_2d(all->game->map);
	map = file_edit(map);
	while (i < 6 && map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			all->texture->no = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			all->texture->so = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			all->texture->we = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			all->texture->ea = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "F", 1) == 0)
			all->texture->f = ft_strdup(map[i] + 1);
		else if (ft_strncmp(map[i], "C", 1) == 0)
			all->texture->c = ft_strdup(map[i] + 1);
		i++;
	}
	init_map_color(all);
	clear_2d_pointer(map);
}
