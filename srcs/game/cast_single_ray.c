#include "../../includes/cub3d.h"

static void	calculate_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	initialize_step_and_side_dist(t_all *all, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (all->game->player_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - all->game->player_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (all->game->player_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - all->game->player_y)
			* ray->delta_dist_y;
	}
}

static void	perform_dda(t_all *all, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || !all->game->map[ray->map_y]
			|| ray->map_x < 0
			|| ray->map_x >= (int)ft_strlen(all->game->map[ray->map_y])
			|| all->game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	calculate_ray_values(t_all *all, t_ray *ray)
{
	if (ray->side == 0)
		ray->distance = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->distance = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->side == 0)
		ray->wall_x = all->game->player_y + ray->distance * ray->ray_dir_y;
	else
		ray->wall_x = all->game->player_x + ray->distance * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->ray_angle = atan2(ray->ray_dir_y, ray->ray_dir_x) * 180 / Y_PI;
	ray->wall_hit = 1;
	ray->wall_y = all->game->player_y + ray->distance * ray->ray_dir_y;
}

t_ray	cast_single_ray(t_all *all, double ray_dir_x, double ray_dir_y)
{
	t_ray	ray;

	ray.ray_dir_x = ray_dir_x;
	ray.ray_dir_y = ray_dir_y;
	ray.map_x = (int)all->game->player_x;
	ray.map_y = (int)all->game->player_y;
	calculate_delta_dist(&ray);
	initialize_step_and_side_dist(all, &ray);
	perform_dda(all, &ray);
	calculate_ray_values(all, &ray);
	return (ray);
}
