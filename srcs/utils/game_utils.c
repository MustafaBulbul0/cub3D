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

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	get_texture_color(t_image *texture, int x, int y)
{
	char	*pixel;

	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
		return (*(int*)pixel);
	}
	return (0);
}
