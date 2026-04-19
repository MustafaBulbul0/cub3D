/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_pixels.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:06:52 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:53:37 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_ceiling_pixels(t_all *all, t_wall *wall)
{
	int	y;
	int	color;

	color = (all->texture->c_color[0] << 16)
		| (all->texture->c_color[1] << 8)
		| all->texture->c_color[2];
	y = 0;
	while (y < wall->wall_start)
	{
		my_mlx_pixel_put(all->mlx->screen, wall->x, y, color);
		y++;
	}
}

static void	draw_floor_pixels(t_all *all, t_wall *wall)
{
	int	y;
	int	color;

	color = (all->texture->f_color[0] << 16)
		| (all->texture->f_color[1] << 8)
		| all->texture->f_color[2];
	y = wall->wall_end + 1;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(all->mlx->screen, wall->x, y, color);
		y++;
	}
}

static void	draw_textured_wall_pixels(t_all *all, t_wall *wall)
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;
	int		tex_y;

	step = 1.0 * wall->texture->height / wall->wall_height;
	tex_pos = (wall->wall_start - SCREEN_HEIGHT / 2 + wall->wall_height / 2)
		* step;
	y = wall->wall_start;
	while (y <= wall->wall_end)
	{
		tex_y = (int)tex_pos & (wall->texture->height - 1);
		tex_pos += step;
		color = get_texture_color(wall->texture, wall->tex_x, tex_y);
		if (wall->ray.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(all->mlx->screen, wall->x, y, color);
		y++;
	}
}

static void	draw_solid_wall_pixels(t_all *all, t_wall *wall)
{
	int	y;
	int	color;

	color = 0x808080;
	if (wall->ray.side == 1)
		color = 0x404040;
	y = wall->wall_start;
	while (y <= wall->wall_end)
	{
		my_mlx_pixel_put(all->mlx->screen, wall->x, y, color);
		y++;
	}
}

void	draw_wall_column(t_all *all, t_wall *wall)
{
	draw_ceiling_pixels(all, wall);
	if (wall->texture && wall->texture->addr)
		draw_textured_wall_pixels(all, wall);
	else
		draw_solid_wall_pixels(all, wall);
	draw_floor_pixels(all, wall);
}
