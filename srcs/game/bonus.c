#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, t_all *all)
{
	static int	last_x;
	int			delta_x;
	double		sensitivity;	

	(void)y;
	last_x = SCREEN_WIDTH / 2;
	if (all->game->first_move)
	{
		last_x = x;
		all->game->first_move = 0;
		return (0);
	}
	sensitivity = 0.005;
	delta_x = x - last_x;
	if (abs(delta_x) < 2)
		return (0);
	all->game->player_angle += delta_x * sensitivity;
	if (all->game->player_angle >= 360.0)
		all->game->player_angle -= 360.0;
	if (all->game->player_angle < 0.0)
		all->game->player_angle += 360.0;
	if (abs(delta_x) > 20)
	{
		mlx_mouse_move(all->mlx->mlx, all->mlx->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		last_x = SCREEN_WIDTH / 2;
	}
	else
		last_x = x;
	return (0);
}
