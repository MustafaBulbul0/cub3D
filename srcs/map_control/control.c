#include "../../includes/cub3d.h"

void	file_control(int ac, char **av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	if (ac != 2 || !av[1])
		exit_print("Map file missing.", NULL);
	s = av[1];
	if (ft_strlen(s) < 4)
		exit_print("The map file  incorrect.", NULL);
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".cub", 4))
		exit_print("The map file format is incorrect.", NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_print("The file could not be opened.", NULL);
	close (fd);
}
int	name_control(char *s)
{
	int	i;

	i = 0;
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".xpm", 4) == 0)
		return (1);
	return (0);
}

int	color_control(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (48 <= s[0] && s[0] <= 57)
		j++;
	while (s[i])
	{
		if (s[i] == ',' && (48 <= s[i + 1] && s[i + 1] <= 57))
			j++;
		i++;
	}
	if (j == 3)
		return (1);
	return (0);
}

void texture_control(t_all *all)
{
	if (!all->texture->no || name_control(all->texture->no) == 0)
		exit_print("Texture missing.", all);
	if (!all->texture->so || name_control(all->texture->so) == 0)
		exit_print("Texture missing.", all);
	if (!all->texture->we || name_control(all->texture->we) == 0)
		exit_print("Texture missing.", all);
	if (!all->texture->ea || name_control(all->texture->ea) == 0)
		exit_print("Texture missing.", all);
	if (!all->texture->f || color_control(all->texture->f) == 0)
		exit_print("Texture missing.", all);
	if (!all->texture->c || color_control(all->texture->c) == 0)
		exit_print("Texture missing.", all);
	

}

void	map_control(t_all *all)
{
	texture_control(all);
	map_character(all);
	wall_control(all);
}