#include "../../includes/cub3d.h"

static void	player_init(t_all *all)
{
	int		i;
	int		j;
	char	**map;

	all->game->player_position = ft_calloc(2, sizeof(int));
	map = all->game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
					all->game->player_position[0] = j;
					all->game->player_position[1] = i;
			}
			j++;
		}
		i++;
	}
}

static void	calculate_sin_cos(t_all *all)
{
	double	*sin_tab;
	double	*cos_tab;
	int	i;

	sin_tab = malloc(360 * sizeof(double));
	cos_tab = malloc(360 * sizeof(double));
	i = 0;
	while (i < 360)
	{
		sin_tab[i] = sin(Y_PI * i / 180);
		cos_tab[i] = cos(Y_PI * i / 180);
		i++;
	}
	all->game->sin_tab = sin_tab;
	all->game->cos_tab = cos_tab;
}

void	start_game(t_all *all)
{
	player_init(all);
	calculate_sin_cos(all);
	
	all->mlx->mlx = mlx_init();
	all->mlx->win = mlx_new_window(all->mlx->mlx, 1920, 1080, "cube3D");
	mlx_loop(all->mlx->mlx);
}
