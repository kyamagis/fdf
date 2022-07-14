/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:17:27 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/14 14:32:19 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	my_mlx_pixel_put(t_map_data *m_d, size_t x, size_t y, int color)
{
	char	*dst;

	if (WINDOW_WIDTH <= x || WINDOW_DEPETH <= y)
		return ;
	dst = m_d->addr + (y * m_d->line_length + x * (m_d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	correspond_to_quadrant(t_map_data *m_d)
{
	m_d->x_direction = 1;
	m_d->y_direction = 1;
	if (m_d->dx < 0)
	{
		m_d->dx *= -1;
		m_d->x_direction = -1;
	}
	if (m_d->dy < 0)
	{
		m_d->dy *= -1;
		m_d->y_direction = -1;
	}
}

void	bresenham_start_point(t_map_data *m_d, int colour)
{
	m_d->dx = m_d->x1_iso - m_d->x_iso;
	m_d->dy = m_d->y1_iso - m_d->y_iso;
	correspond_to_quadrant(m_d);
	if (m_d->dy <= m_d->dx)
		m_d->discrim = 2 * m_d->dy - m_d->dx;
	else
		m_d->discrim = 2 * m_d->dx - m_d->dy;
	my_mlx_pixel_put(m_d, m_d->x_iso, m_d->y_iso, colour);
}

static void	bresenham_discriminant(t_map_data *m_d, double dx, double dy)
{
	if (m_d->discrim < 0)
		m_d->discrim += 2 * dy;
	else
		m_d->discrim += 2 * (dy - dx);
}

void	bresenham_line(t_map_data *m_d, double x, double y, int colour)
{
	my_mlx_pixel_put(m_d, x, y, colour);
	if (m_d->dy < m_d->dx)
		bresenham_discriminant(m_d, m_d->dx, m_d->dy);
	else
		bresenham_discriminant(m_d, m_d->dy, m_d->dx);
}
