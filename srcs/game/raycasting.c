#include "../../includes/cub3d.h"

static void	draw_ceiling_pixels(t_all *all, int x, int wall_start)
{
	int	y;
	int	color;

	color = (all->texture->c_color[0] << 16)
		| (all->texture->c_color[1] << 8)
		| all->texture->c_color[2];
	y = 0;
	while (y < wall_start)
	{
		my_mlx_pixel_put(all->mlx->screen, x, y, color);
		y++;
	}
}

static void	draw_floor_pixels(t_all *all, int x, int wall_end)
{
	int	y;
	int	color;

	color = (all->texture->f_color[0] << 16)
		| (all->texture->f_color[1] << 8)
		| all->texture->f_color[2];
	y = wall_end + 1;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(all->mlx->screen, x, y, color);
		y++;
	}
}

static int	calculate_wall_bounds(t_ray ray, int *wall_start, int *wall_end)
{
	int	wall_height;

	wall_height = (int)(SCREEN_HEIGHT / ray.distance);
	*wall_start = -wall_height / 2 + SCREEN_HEIGHT / 2;
	*wall_end = wall_height / 2 + SCREEN_HEIGHT / 2;
	if (*wall_start < 0)
		*wall_start = 0;
	if (*wall_end >= SCREEN_HEIGHT)
		*wall_end = SCREEN_HEIGHT - 1;
	return (wall_height);
}

static t_image	*get_wall_texture(t_all *all,
	t_ray ray, double ray_dir_x, double ray_dir_y)
{
	if (ray.side == 0)
	{
		if (ray_dir_x > 0)
			return (all->mlx->ea_texture);
		else
			return (all->mlx->we_texture);
	}
	else
	{
		if (ray_dir_y > 0)
			return (all->mlx->so_texture);
		else
			return (all->mlx->no_texture);
	}
}

static int	calculate_tex_x(t_ray ray, t_image *texture,
	double ray_dir_x, double ray_dir_y)
{
	int	tex_x;

	if (!texture)
		return (0);
	tex_x = (int)(ray.wall_x * (double)texture->width);
	if (ray.side == 0 && ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray.side == 1 && ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

static void	draw_textured_wall_pixels(t_all *all, int x,
	int wall_start, int wall_end, t_image *texture, int tex_x,
	t_ray ray, int wall_height)
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;
	int		tex_y;

	step = 1.0 * texture->height / wall_height;
	tex_pos = (wall_start - SCREEN_HEIGHT / 2 + wall_height / 2) * step;
	y = wall_start;
	while (y <= wall_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_texture_color(texture, tex_x, tex_y);
		if (ray.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(all->mlx->screen, x, y, color);
		y++;
	}
}

static void	draw_solid_wall_pixels(t_all *all, int x,
	int wall_start, int wall_end, t_ray ray)
{
	int	y;
	int	color;

	color = 0x808080;
	if (ray.side == 1)
		color = 0x404040;
	y = wall_start;
	while (y <= wall_end)
	{
		my_mlx_pixel_put(all->mlx->screen, x, y, color);
		y++;
	}
}

static void	draw_wall_column(t_all *all, int x, t_ray ray,
	double ray_dir_x, double ray_dir_y)
{
	int		wall_start;
	int		wall_end;
	int		wall_height;
	t_image	*texture;
	int		tex_x;

	wall_height = calculate_wall_bounds(ray, &wall_start, &wall_end);
	texture = get_wall_texture(all, ray, ray_dir_x, ray_dir_y);
	tex_x = calculate_tex_x(ray, texture, ray_dir_x, ray_dir_y);
	draw_ceiling_pixels(all, x, wall_start);
	if (texture && texture->addr)
		draw_textured_wall_pixels(all, x, wall_start, wall_end, texture, tex_x, ray, wall_height);
	else
		draw_solid_wall_pixels(all, x, wall_start, wall_end, ray);
	draw_floor_pixels(all, x, wall_end);
}

void	cast_rays(t_all *all)
{
	int		x;
	double	camera_x;
	t_ray	ray;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;

	dir_x = cos(all->game->player_angle * Y_PI / 180);
	dir_y = sin(all->game->player_angle * Y_PI / 180);
	plane_x = -dir_y * tan(VIEWING_ANGLE / 2 * Y_PI / 180);
	plane_y = dir_x * tan(VIEWING_ANGLE / 2 * Y_PI / 180);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_x;
		ray = cast_single_ray(all, ray_dir_x, ray_dir_y);
		draw_wall_column(all, x, ray, ray_dir_x, ray_dir_y);
		x++;
	}
}

void	render_screen(t_all *all)
{
	cast_rays(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win,
		all->mlx->screen->img, 0, 0);
}
