#include "../../includes/cub3d.h"

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		clear_2d_pointer(game->map);
		game->map = NULL;
	}
	if (game->player_position)
	{
		free(game->player_position);
		game->player_position = NULL;
	}
	if (game->sin_tab)
	{
		free(game->sin_tab);
		game->sin_tab = NULL;
	}
	if (game->cos_tab)
	{
		free(game->cos_tab);
		game->cos_tab = NULL;
	}
	free(game);
}

void	ft_free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->no)
	{
		free(texture->no);
		texture->no = NULL;
	}
	if (texture->so)
	{
		free(texture->so);
		texture->so = NULL;
	}
	if (texture->we)
	{
		free(texture->we);
		texture->we = NULL;
	}
	if (texture->ea)
	{
		free(texture->ea);
		texture->ea = NULL;
	}
	if (texture->f)
	{
		free(texture->f);
		texture->f = NULL;
	}
	if (texture->c)
	{
		free(texture->c);
		texture->c = NULL;
	}
	free(texture);
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->no_img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->no_img);
	if (mlx->so_img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->so_img);
	if (mlx->we_img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->we_img);
	if (mlx->ea_img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->ea_img);
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

void	shut_program_error(t_all *all, char *s)
{
	ft_free_all(all);
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
