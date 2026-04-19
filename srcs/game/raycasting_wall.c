/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:05:13 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:53:44 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static t_image	*get_wall_texture(t_all *all, t_ray ray, double ray_dir[2])
{
	if (ray.side == 0)
	{
		if (ray_dir[0] > 0)
			return (all->mlx->ea_texture);
		return (all->mlx->we_texture);
	}
	if (ray_dir[1] > 0)
		return (all->mlx->so_texture);
	return (all->mlx->no_texture);
}

static int	calculate_tex_x(t_ray ray, t_image *texture, double ray_dir[2])
{
	int	tex_x;

	if (!texture)
		return (0);
	tex_x = (int)(ray.wall_x * (double)texture->width);
	if (ray.side == 0 && ray_dir[0] > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray.side == 1 && ray_dir[1] < 0)
		tex_x = texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

void	init_wall_draw(t_all *all, t_wall *wall, double ray_dir[2])
{
	wall->ray_dir[0] = ray_dir[0];
	wall->ray_dir[1] = ray_dir[1];
	wall->wall_height = calculate_wall_bounds(wall->ray,
			&wall->wall_start, &wall->wall_end);
	wall->texture = get_wall_texture(all, wall->ray, wall->ray_dir);
	wall->tex_x = calculate_tex_x(wall->ray, wall->texture, wall->ray_dir);
}
