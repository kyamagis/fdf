/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:24:09 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/14 14:33:48 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	move_to_window_centr_x(t_map_data *m_d, double x_iso)
{
	x_iso = x_iso * m_d->zoom + (WINDOW_WIDTH / 2) + m_d->right_left;
	return (x_iso);
}

static double	move_to_window_centr_y(t_map_data *m_d, double y1_iso)
{
	y1_iso = y1_iso * m_d->zoom + (WINDOW_DEPETH / 2) + m_d->up_down;
	return (y1_iso);
}

static void	rotation_move_next_point(t_map_data *m_d, size_t x, size_t y)
{
	if (m_d->width <= x || m_d->depth <= y)
		return ;
	rotation(m_d, x, y);
	m_d->x1_iso = m_d->rotated_x;
	m_d->y1_iso = m_d->rotated_y;
	m_d->x1_iso = move_to_window_centr_x(m_d, m_d->x1_iso);
	m_d->y1_iso = move_to_window_centr_y(m_d, m_d->y1_iso);
}

void	rotation_move(t_map_data *m_d, size_t x, size_t y, int axis)
{
	rotation(m_d, x, y);
	m_d->x_iso = m_d->rotated_x;
	m_d->y_iso = m_d->rotated_y;
	m_d->x_iso = move_to_window_centr_x(m_d, m_d->x_iso);
	m_d->y_iso = move_to_window_centr_y(m_d, m_d->y_iso);
	if (axis == X)
		rotation_move_next_point(m_d, x + 1, y);
	if (axis == Y)
		rotation_move_next_point(m_d, x, y + 1);
}
