#include "../../includes/cub3d.h"

int	key_press(int keycode, t_all *all)
{
	if (keycode == 65307)
		all->game->keys.esc = 1;
	else if (keycode == 119)
		all->game->keys.w = 1;
	else if (keycode == 115)
		all->game->keys.s = 1;
	else if (keycode == 97)
		all->game->keys.a = 1;
	else if (keycode == 100)
		all->game->keys.d = 1;
	else if (keycode == 65361)
		all->game->keys.left = 1;
	else if (keycode == 65363)
		all->game->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	if (keycode == 65307)
		all->game->keys.esc = 0;
	else if (keycode == 119)
		all->game->keys.w = 0;
	else if (keycode == 115)
		all->game->keys.s = 0;
	else if (keycode == 97)
		all->game->keys.a = 0;
	else if (keycode == 100)
		all->game->keys.d = 0;
	else if (keycode == 65361)
		all->game->keys.left = 0;
	else if (keycode == 65363)
		all->game->keys.right = 0;
	return (0);
}
