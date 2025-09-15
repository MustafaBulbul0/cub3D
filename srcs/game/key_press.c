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

void	handle_movement(t_all *all)
{
	if (all->game->keys.esc)
	{
		ft_free_all(all);
		exit(0);
	}
	if (all->game->keys.w)
		move_forward(all);
	if (all->game->keys.s)
		move_backward(all);
	if (all->game->keys.a)
		move_left(all);
	if (all->game->keys.d)
		move_right(all);
	if (all->game->keys.left)
	{
		all->game->player_angle -= ROTATE_SPEED;
		if (all->game->player_angle < 0)
			all->game->player_angle += 360;
	}
	if (all->game->keys.right)
	{
		all->game->player_angle += ROTATE_SPEED;
		if (all->game->player_angle >= 360)
			all->game->player_angle -= 360;
	}
}

