#include "../../includes/cub3d.h"

int	key_press(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		ft_free_all(all);
		exit (0);
	}
	return (0);
}
