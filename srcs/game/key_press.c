#include "../../includes/cub3d.h"

static void	move_forward(t_all *all)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = all->game->player_angle * Y_PI / 180;
	new_x = all->game->player_x + cos(rad) * MOVE_SPEED;
	new_y = all->game->player_y + sin(rad) * MOVE_SPEED;
	if ((int)new_y >= 0 && all->game->map[(int)new_y] &&
		(int)new_x >= 0 && (int)new_x < (int)ft_strlen(all->game->map[(int)new_y]) &&
		all->game->map[(int)new_y][(int)new_x] != '1')
	{
		all->game->player_x = new_x;
		all->game->player_y = new_y;
	}
}

static void	move_backward(t_all *all)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = all->game->player_angle * Y_PI / 180;	
	new_x = all->game->player_x - cos(rad) * MOVE_SPEED;
	new_y = all->game->player_y - sin(rad) * MOVE_SPEED;
	if ((int)new_y >= 0 && all->game->map[(int)new_y] &&
		(int)new_x >= 0 && (int)new_x < (int)ft_strlen(all->game->map[(int)new_y]) &&
		all->game->map[(int)new_y][(int)new_x] != '1')
	{
		all->game->player_x = new_x;
		all->game->player_y = new_y;
	}
}

static void	move_left(t_all *all)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = (all->game->player_angle - 90) * Y_PI / 180;
	new_x = all->game->player_x + cos(rad) * MOVE_SPEED;
	new_y = all->game->player_y + sin(rad) * MOVE_SPEED;
	if ((int)new_y >= 0 && all->game->map[(int)new_y] &&
		(int)new_x >= 0 && (int)new_x < (int)ft_strlen(all->game->map[(int)new_y]) &&
		all->game->map[(int)new_y][(int)new_x] != '1')
	{
		all->game->player_x = new_x;
		all->game->player_y = new_y;
	}
}

static void	move_right(t_all *all)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = (all->game->player_angle + 90) * Y_PI / 180;
	new_x = all->game->player_x + cos(rad) * MOVE_SPEED;
	new_y = all->game->player_y + sin(rad) * MOVE_SPEED;
	if ((int)new_y >= 0 && all->game->map[(int)new_y] &&
		(int)new_x >= 0 && (int)new_x < (int)ft_strlen(all->game->map[(int)new_y]) &&
		all->game->map[(int)new_y][(int)new_x] != '1')
	{
		all->game->player_x = new_x;
		all->game->player_y = new_y;
	}
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		ft_free_all(all);
		exit (0);
	}
	else if (keycode == 119)
		move_forward(all);
	else if (keycode == 115)
		move_backward(all);
	else if (keycode == 97)
		move_left(all);
	else if (keycode == 100)
		move_right(all);
	else if (keycode == 65361)
		all->game->player_angle -= ROTATE_SPEED * Y_PI / 180;
	else if (keycode == 65363)
		all->game->player_angle += ROTATE_SPEED * Y_PI / 180;
	return (0);
}
