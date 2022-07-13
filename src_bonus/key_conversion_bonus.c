/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_conversion_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:36:43 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/12 12:19:10 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	view_change(t_map_data *m_d)
{
	m_d->x_rad = 0;
	m_d->y_rad = 0;
	m_d->z_rad = 0;
	mlx_destroy_image(m_d->mlx, m_d->img);
	init(m_d);
	draw_map(m_d);
}

static void	parallel_translation(int keycode, t_map_data *m_d)
{
	if (keycode == UP)
		m_d->up_down -= 10;
	if (keycode == DOWN)
		m_d->up_down += 10;
	if (keycode == RIGHT)
		m_d->right_left += 10;
	if (keycode == LEFT)
		m_d->right_left -= 10;
	mlx_destroy_image(m_d->mlx, m_d->img);
	init(m_d);
	draw_map(m_d);
}

static void	zoom(int keycode, t_map_data *m_d)
{
	if (keycode == ZOOM_IN)
		m_d->zoom *= 2;
	if (m_d->zoom <= 1)
		return ;
	if (keycode == ZOOM_OUT)
		m_d->zoom /= 2;
	mlx_destroy_image(m_d->mlx, m_d->img);
	init(m_d);
	draw_map(m_d);
}

static void	rotate_conversion(int keycode, t_map_data *m_d)
{
	if (keycode == X_CLOCKWISE)
		m_d->x_rad += M_PI / 12;
	if (keycode == X_CCLOCKWISE)
		m_d->x_rad -= M_PI / 12;
	if (keycode == Y_CLOCKWISE)
		m_d->y_rad += M_PI / 12;
	if (keycode == Y_CCLOCKWISE)
		m_d->y_rad -= M_PI / 12;
	if (keycode == Z_CLOCKWISE)
		m_d->z_rad += M_PI / 12;
	if (keycode == Z_CCLOCKWISE)
		m_d->z_rad -= M_PI / 12;
	mlx_destroy_image(m_d->mlx, m_d->img);
	init(m_d);
	draw_map(m_d);
}

int	key_conversion(int keycode, t_map_data *m_d)
{
	if (keycode == ESP_KEY)
		destroy_window(m_d);
	if (keycode == T_OPVIEW)
		view_change(m_d);
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		parallel_translation(keycode, m_d);
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		zoom(keycode, m_d);
	if (keycode == X_CLOCKWISE || keycode == Y_CLOCKWISE || \
		keycode == Z_CLOCKWISE || keycode == X_CCLOCKWISE || \
		keycode == Y_CCLOCKWISE || keycode == Z_CCLOCKWISE)
		rotate_conversion(keycode, m_d);
	if (keycode == INITIAL_POSITION)
		initial_position(m_d);
	if (keycode == WAVE)
		wave(m_d);
	if (keycode == SCAN)
		scan(m_d);
	return (0);
}
