/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_conversion2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:36:43 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 16:19:58 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initial_position(t_map_data *m_d)
{
	position_init(m_d);
	draw_map(m_d);
}

void	wave(t_map_data *m_d)
{
	m_d->wave += 1;
	if ((int)m_d->depth == m_d->wave)
		m_d->wave = -1;
	init(m_d);
	draw_map(m_d);
}

void	scan(t_map_data *m_d)
{
	m_d->scan += 1;
	if ((int)m_d->depth == m_d->scan)
		m_d->scan = -1;
	init(m_d);
	draw_map(m_d);
}
