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
	free(all);
}

void	shut_program_error(t_all *all, char *s)
{
	ft_free_all(all);
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
