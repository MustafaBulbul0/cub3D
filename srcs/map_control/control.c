/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:27:32 by mustafa           #+#    #+#             */
/*   Updated: 2025/09/03 01:56:22 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	file_control(int ac, char **av)
{
	int		i;
	int		fd;
	char	*s;

	printf("%d\n", ac);
	if (ac != 2 || !av[1])
		exit_print("Map file missing.");
	s = av[1];
	if (strlen(s) < 4)
		exit_print("The map file  incorrect.");
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".cub", 4))
		exit_print("The map file format is incorrect.");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("The file could not be opened: %s\n", strerror(errno));
		exit(errno);
	}
	close (fd);
}
