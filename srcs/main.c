/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:05:46 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 12:05:47 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	all_structs = map_control(ac, av);
	start_game(all_structs);
	ft_free_all(all_structs);
	return (0);
}
