/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:47:38 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:57:29 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_camera(t_all *all, double camera[4])
{
	camera[0] = cos(all->game->player_angle * Y_PI / 180);
	camera[1] = sin(all->game->player_angle * Y_PI / 180);
	camera[2] = -camera[1] * tan(VIEWING_ANGLE / 2 * Y_PI / 180);
	camera[3] = camera[0] * tan(VIEWING_ANGLE / 2 * Y_PI / 180);
}

static void	update_ray_dir(int x, double camera[4], double ray_dir[2])
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray_dir[0] = camera[0] + camera[2] * camera_x;
	ray_dir[1] = camera[1] + camera[3] * camera_x;
}

void	cast_rays(t_all *all)
{
	int		x;
	t_ray	ray;
	double	camera[4];
	double	ray_dir[2];
	t_wall	wall;

	init_camera(all, camera);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		update_ray_dir(x, camera, ray_dir);
		ray = cast_single_ray(all, ray_dir[0], ray_dir[1]);
		wall.x = x;
		wall.ray = ray;
		init_wall_draw(all, &wall, ray_dir);
		draw_wall_column(all, &wall);
		x++;
	}
}

void	render_screen(t_all *all)
{
	cast_rays(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win,
		all->mlx->screen->img, 0, 0);
}
