/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:06:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 16:26:26 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	z_rotation(t_map_data *m_d, double x, double y)
{
	m_d->rotated_x = x * cos(m_d->z_rad) - y * sin(m_d->z_rad);
	m_d->rotated_y = x * sin(m_d->z_rad) + y * cos(m_d->z_rad);
}

static void	x_rotation(t_map_data *m_d, double y, int z)
{
	m_d->rotated_y = y * cos(m_d->x_rad) - z * sin(m_d->x_rad);
	m_d->rotated_z = -y * sin(m_d->x_rad) + z * cos(m_d->x_rad);
}

static void	y_rotation(t_map_data *m_d, double x, double z)
{
	m_d->rotated_x = x * cos(m_d->y_rad) + z * sin(m_d->y_rad);
	m_d->rotated_z = -x * sin(m_d->y_rad) + z * cos(m_d->y_rad);
}

static void	move_to_map_center(t_map_data *m_d, size_t x, size_t y)
{
	m_d->map_center_x = x - (m_d->width / 2);
	m_d->map_center_y = y - (m_d->depth / 2);
}

void	rotation(t_map_data *m_d, size_t x, size_t y)
{
	move_to_map_center(m_d, x, y);
	z_rotation(m_d, m_d->map_center_x, m_d->map_center_y);
	if (m_d->wave != (int)y)
		x_rotation(m_d, m_d->rotated_y, m_d->height[y][x]);
	if (m_d->wave == (int)y)
		x_rotation(m_d, m_d->rotated_y, m_d->height[y][x] + 10);
	y_rotation(m_d, m_d->rotated_x, m_d->rotated_z);
}
