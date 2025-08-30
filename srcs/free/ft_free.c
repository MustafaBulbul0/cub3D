#include "../../librarys/cub3d.h"

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	clear_2d_pointer(game->map);
	free(game);
}

void	ft_free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	free(texture);
}

void	ft_free_all(t_all *all)
{
	if (!all)
		return ;
	ft_free_game(all->game);
	ft_free_texture(all->texture);
	free(all);
}

void	shut_program_error(t_all *all, char *s)
{
	ft_free_all(all);
	printf("%s\n", s);
	exit (EXIT_FAILURE);
}
