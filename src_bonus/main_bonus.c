/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:08:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/12 12:22:42 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	destroy_window(t_map_data *m_d)
{
	mlx_destroy_window(m_d->mlx, m_d->window);
	exit(0);
	return (0);
}

void	ft_exit(char *error_type)
{
	ft_putendl_fd(error_type, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map_data	*m_d;

	if (argc != 2)
		ft_exit(ARG_ERROR);
	m_d = (t_map_data *)malloc(sizeof(t_map_data));
	if (m_d == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	map_data_init(m_d);
	open_read(argv[1], m_d);
	draw_map(m_d);
	mlx_hook(m_d->window, 2, 0, key_conversion, m_d);
	mlx_hook(m_d->window, 17, 0, destroy_window, m_d);
	mlx_loop(m_d->mlx);
	return (0);
}

/*
__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q fdf");
}
*/