/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:41:16 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:45:25 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_image(t_mlx *mlx, t_image **img)
{
	if (!*img)
		return ;
	if ((*img)->img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, (*img)->img);
	free(*img);
	*img = NULL;
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		clear_2d_pointer(game->map);
		game->map = NULL;
	}
	free(game);
}

void	ft_free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->no)
		free(texture->no);
	if (texture->so)
		free(texture->so);
	if (texture->we)
		free(texture->we);
	if (texture->ea)
		free(texture->ea);
	if (texture->f)
		free(texture->f);
	if (texture->c)
		free(texture->c);
	free(texture);
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	destroy_image(mlx, &mlx->no_texture);
	destroy_image(mlx, &mlx->so_texture);
	destroy_image(mlx, &mlx->we_texture);
	destroy_image(mlx, &mlx->ea_texture);
	destroy_image(mlx, &mlx->screen);
	if (mlx->win && mlx->mlx)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx);
}

void	ft_free_all(t_all *all)
{
	if (!all)
		return ;
	if (all->game)
	{
		ft_free_game(all->game);
		all->game = NULL;
	}
	if (all->texture)
	{
		ft_free_texture(all->texture);
		all->texture = NULL;
	}
	if (all->mlx)
	{
		ft_free_mlx(all->mlx);
		all->mlx = NULL;
	}
	free(all);
}
