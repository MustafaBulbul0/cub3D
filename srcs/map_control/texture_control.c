#include "../../includes/cub3d.h"

static int	name_control(char *s)
{
	int	i;

	i = 0;
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".xpm", 4) == 0)
		return (1);
	return (0);
}

static int	color_control(char *s)
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

void	texture_control(t_all *all)
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
