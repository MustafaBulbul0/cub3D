#include "../../includes/cub3d.h"

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

char	*ft_realloc(char *s, int size)
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

void	exit_print(char *s, t_all *all)
{
	printf("Error :%s\n", s);
	if (all)
		ft_free_all(all);
	exit (EXIT_FAILURE);
}

void init_all_structs(t_all *all)
{
	all->game = malloc(sizeof(t_game));
	if (!all->game)
		exit_print("Malloc failed.", all);
	all->game->map = NULL;
	all->texture = malloc(sizeof(t_texture));
	if (!all->texture)
		exit_print("Malloc failed.", all);
	all->texture->no = NULL;
	all->texture->so = NULL;
	all->texture->we = NULL;
	all->texture->ea = NULL;
	all->texture->f = NULL;
	all->texture->c = NULL;
}
