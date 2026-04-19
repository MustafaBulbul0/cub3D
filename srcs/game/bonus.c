/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:59:22 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:59:23 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_player_angle(t_all *all, int delta_x)
{
	double	sensitivity;

	sensitivity = 0.005;
	all->game->player_angle += delta_x * sensitivity;
	if (all->game->player_angle >= 360.0)
		all->game->player_angle -= 360.0;
	if (all->game->player_angle < 0.0)
		all->game->player_angle += 360.0;
}

static void	update_mouse_position(t_all *all, int x, int *last_x, int delta_x)
{
	if (abs(delta_x) > 20)
	{
		mlx_mouse_move(all->mlx->mlx, all->mlx->win,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		*last_x = SCREEN_WIDTH / 2;
	}
	else
		*last_x = x;
}

int	mouse_move(int x, int y, t_all *all)
{
	static int	last_x;
	int			delta_x;

	(void)y;
	last_x = SCREEN_WIDTH / 2;
	if (all->game->first_move)
	{
		last_x = x;
		all->game->first_move = 0;
		return (0);
	}
	delta_x = x - last_x;
	if (abs(delta_x) < 2)
		return (0);
	update_player_angle(all, delta_x);
	update_mouse_position(all, x, &last_x, delta_x);
	return (0);
}
