#include "../../includes/cub3d.h"

static void	player_init(t_all *all)
{
	int		i;
	int		j;
	char	**map;

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
					all->game->player_x = j + 0.5;
					all->game->player_y = i + 0.5;
					if (map[i][j] == 'E')
						all->game->player_angle = 0;
					else if (map[i][j] == 'N')
						all->game->player_angle = 90;
					if (map[i][j] == 'W')
						all->game->player_angle = 180;
					if (map[i][j] == 'S')
						all->game->player_angle = 270;
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

int	game_loop(t_all *all)
{
	handle_movement(all);
	//render_screen(all);
	return (0);
}

void	start_game(t_all *all)
{
	player_init(all);
	calculate_sin_cos(all);

	all->mlx->mlx = mlx_init();
	if (!all->mlx->mlx)
		exit_print("MLX initialization failed.", all);
	all->mlx->win = mlx_new_window(all->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!all->mlx->win)
		exit_print("Window creation failed.", all);
	load_textures(all);
	mlx_hook(all->mlx->win, 2, 1L<<0, key_press, all);
	mlx_hook(all->mlx->win, 3, 1L<<1, key_release, all);
	mlx_hook(all->mlx->win, 17, 0, close_windows, all);
	mlx_loop_hook(all->mlx->mlx, game_loop, all);
	mlx_loop(all->mlx->mlx);
}
