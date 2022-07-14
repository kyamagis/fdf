/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:29:35 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/14 14:32:42 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	absolute_value(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

static void	draw_line(t_map_data *m_d, int colour)
{
	double	x_direct;
	double	y_direct;

	x_direct = 0;
	y_direct = 0;
	while (0 < (int)(m_d->dx - absolute_value(x_direct)) || \
			0 < (int)(m_d->dy - absolute_value(y_direct)))
	{
		if (m_d->dx < m_d->dy)
		{
			if (0 <= m_d->discrim)
				x_direct += m_d->x_direction;
			y_direct += m_d->y_direction;
		}
		else
		{
			if (0 <= m_d->discrim)
				y_direct += m_d->y_direction;
			x_direct += m_d->x_direction;
		}
		bresenham_line(m_d, m_d->x_iso + x_direct, \
						m_d->y_iso + y_direct, colour);
	}
}

static void	draw_width(t_map_data *m_d, size_t x, size_t y)
{
	rotation_move(m_d, x, y, X);
	bresenham_start_point(m_d, m_d->colour[y][x]);
	if (x < m_d->width - 1 )
		draw_line(m_d, m_d->colour[y][x]);
}

static void	draw_depth(t_map_data *m_d, size_t x, size_t y)
{
	if (m_d->scan == (int)y)
		return ;
	rotation_move(m_d, x, y, Y);
	bresenham_start_point(m_d, m_d->colour[y][x]);
	if (y < m_d->depth - 1)
		draw_line(m_d, m_d->colour[y][x]);
}

void	draw_map(t_map_data *m_d)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < m_d->depth && (m_d->scan == -1 || (int)y <= m_d->scan))
	{
		x = 0;
		while (x < m_d->width)
		{
			draw_width(m_d, x, y);
			draw_depth(m_d, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m_d->mlx, m_d->window, m_d->img, 0, 0);
}
