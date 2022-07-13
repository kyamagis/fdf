/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_height_colour_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:02:32 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 16:26:01 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	free_splitln(char **split_line, t_map_data *m_d)
{
	size_t	i;

	i = 0;
	while (i < m_d->width)
	{
		free (split_line[i]);
		i++;
	}
	free (split_line);
}

static void	atoi_height_colour(char **split_line, t_map_data *m_d, size_t row)
{
	size_t	column;

	m_d->height[row] = (int *)malloc(sizeof(int) * (m_d->width));
	if (m_d->height == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	m_d->colour[row] = (int *)malloc(sizeof(int) * (m_d->width));
	if (m_d->colour == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	column = 0;
	while (split_line[column] != NULL)
	{
		m_d->height[row][column] = ft_atoi(split_line[column]);
		m_d->colour[row][column] = atoi_hex(split_line[column]);
		column++;
	}
}

void	divide_height_colour(t_list_split *l_s, t_map_data *m_d)
{
	t_list_split	*tent;
	t_list_split	*temp;
	size_t			row;

	m_d->height = (int **)malloc(sizeof(int *) * m_d->depth);
	if (m_d->height == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	m_d->colour = (int **)malloc(sizeof(int *) * m_d->depth);
	if (m_d->colour == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	tent = l_s;
	row = 0;
	while (tent->next)
	{
		temp = tent->next;
		atoi_height_colour(tent->split_line, m_d, row);
		free_splitln(tent->split_line, m_d);
		row++;
		free(tent);
		tent = temp;
	}
	free(temp);
}
