/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_program_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:37:15 by mubulbul          #+#    #+#             */
/*   Updated: 2026/04/19 13:45:17 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	shut_program_error(t_all *all, char *s)
{
	ft_free_all(all);
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
