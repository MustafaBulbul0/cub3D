#include "../../includes/cub3d.h"

static void	load_ea(t_all *all)
{
	if (all->texture->ea)
	{
		all->mlx->ea_texture->img = mlx_xpm_file_to_image(all->mlx->mlx, 
			all->texture->ea, &all->mlx->ea_texture->width, 
			&all->mlx->ea_texture->height);
		if (all->mlx->ea_texture->img)
			all->mlx->ea_texture->addr = mlx_get_data_addr(
				all->mlx->ea_texture->img,
				&all->mlx->ea_texture->bits_per_pixel, 
				&all->mlx->ea_texture->line_length, 
				&all->mlx->ea_texture->endian);
	}
}

static void	load_we(t_all *all)
{
	if (all->texture->we)
	{
		all->mlx->we_texture->img = mlx_xpm_file_to_image(all->mlx->mlx, 
			all->texture->we, &all->mlx->we_texture->width, 
			&all->mlx->we_texture->height);
		if (all->mlx->we_texture->img)
			all->mlx->we_texture->addr = mlx_get_data_addr(
				all->mlx->we_texture->img,
				&all->mlx->we_texture->bits_per_pixel, 
				&all->mlx->we_texture->line_length, 
				&all->mlx->we_texture->endian);
	}
}

static void	load_so(t_all *all)
{
	if (all->texture->so)
	{
		all->mlx->so_texture->img = mlx_xpm_file_to_image(all->mlx->mlx, 
			all->texture->so, &all->mlx->so_texture->width, 
			&all->mlx->so_texture->height);
		if (all->mlx->so_texture->img)
			all->mlx->so_texture->addr = mlx_get_data_addr(
				all->mlx->so_texture->img,
				&all->mlx->so_texture->bits_per_pixel, 
				&all->mlx->so_texture->line_length, 
				&all->mlx->so_texture->endian);
	}
}

static void	load_no(t_all *all)
{
	if (all->texture->no)
	{
		all->mlx->no_texture->img = mlx_xpm_file_to_image(all->mlx->mlx, 
			all->texture->no, &all->mlx->no_texture->width, 
			&all->mlx->no_texture->height);
		if (all->mlx->no_texture->img)
			all->mlx->no_texture->addr = mlx_get_data_addr(
				all->mlx->no_texture->img,
				&all->mlx->no_texture->bits_per_pixel, 
				&all->mlx->no_texture->line_length, 
				&all->mlx->no_texture->endian);
	}
}

void	load_textures(t_all *all)
{
	all->mlx->no_texture = ft_calloc(1, sizeof(t_image));
	all->mlx->so_texture = ft_calloc(1, sizeof(t_image));
	all->mlx->we_texture = ft_calloc(1, sizeof(t_image));
	all->mlx->ea_texture = ft_calloc(1, sizeof(t_image));
	all->mlx->screen = ft_calloc(1, sizeof(t_image));
	load_no(all);
	load_so(all);
	load_we(all);
	load_ea(all);
	all->mlx->screen->img = mlx_new_image(all->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->mlx->screen->addr = mlx_get_data_addr(all->mlx->screen->img,
		&all->mlx->screen->bits_per_pixel, 
		&all->mlx->screen->line_length, 
		&all->mlx->screen->endian);
	all->mlx->screen->width = SCREEN_WIDTH;
	all->mlx->screen->height = SCREEN_HEIGHT;
}
