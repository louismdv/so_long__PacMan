/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 19:14:24 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		return (0);
	}
	parse(av[1], &data);
	initiate_mlx(&data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, render_map, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		&close_window, &data);
	mlx_loop(data.mlx);
}
