#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	all_structs = map_control(ac, av);
	start_game(all_structs);

//	printf("%f\n", sin(Y_PI * 30 / 180));
//	void *mlx = mlx_init();
//	mlx_new_window(mlx, 1920, 1080, "dene");
//	mlx_loop(mlx);

	ft_free_all(all_structs);
	return (0);
}
