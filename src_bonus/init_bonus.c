/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:59:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:47 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	map_data_init(t_map_data *m_d)
{
	m_d->mlx = mlx_init();
	m_d->window = mlx_new_window(m_d->mlx, WINDOW_WIDTH, WINDOW_DEPETH, "FDF");
	m_d->depth = 0;
	m_d->width = 0;
	m_d->dx = 0;
	m_d->dy = 0;
	m_d->up_down = 0;
	m_d->right_left = 0;
	m_d->zoom = 30;
	m_d->x_rad = asin(sqrt(2) / sqrt(3));
	m_d->y_rad = 0;
	m_d->z_rad = M_PI_4;
	m_d->wave = -1;
	m_d->scan = -1;
	m_d->img = mlx_new_image(m_d->mlx, WINDOW_WIDTH, WINDOW_DEPETH);
	m_d->addr = mlx_get_data_addr(m_d->img, &m_d->bits_per_pixel, \
								&m_d->line_length, &m_d->endian);
}

void	init(t_map_data *m_d)
{
	m_d->img = mlx_new_image(m_d->mlx, WINDOW_WIDTH, WINDOW_DEPETH);
	m_d->addr = mlx_get_data_addr(m_d->img, &m_d->bits_per_pixel, \
								&m_d->line_length, &m_d->endian);
}

void	position_init(t_map_data *m_d)
{
	m_d->up_down = 0;
	m_d->right_left = 0;
	m_d->x_rad = asin(sqrt(2) / sqrt(3));
	m_d->y_rad = 0;
	m_d->z_rad = M_PI_4;
	m_d->wave = -1;
	m_d->scan = -1;
	m_d->img = mlx_new_image(m_d->mlx, WINDOW_WIDTH, WINDOW_DEPETH);
	m_d->addr = mlx_get_data_addr(m_d->img, &m_d->bits_per_pixel, \
								&m_d->line_length, &m_d->endian);
}
