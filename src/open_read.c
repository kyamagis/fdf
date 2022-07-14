/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:20:01 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/14 14:33:30 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_list_split	*newlst(char **str)
{
	t_list_split	*tmp;

	tmp = (t_list_split *)malloc(sizeof(t_list_split));
	if (tmp == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	tmp->split_line = str;
	tmp->next = NULL;
	return (tmp);
}

static size_t	count_width(char **split_line)
{
	size_t	column;

	column = 0;
	while (split_line[column] != NULL)
	{
		column++;
		if (10000 < column)
			exit(1);
	}
	return (column);
}

static void	count_depth_width(char **split_line, t_map_data *m_d)
{
	if (m_d->depth == 0)
		m_d->width = count_width(split_line);
	else
	{
		if (m_d->width != count_width(split_line))
			ft_exit(LINE_ERROR);
	}
	m_d->depth += 1;
	if (10000 < m_d->depth)
		exit(1);
}

static void	read_file(int fd, t_list_split *l_s, t_map_data *m_d)
{
	t_list_split	*tent;
	char			*read_line;

	tent = l_s;
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		tent->split_line = ft_split(read_line, ' ');
		free(read_line);
		count_depth_width(tent->split_line, m_d);
		tent->next = newlst(NULL);
		tent = tent->next;
	}
}

void	open_read(char *argv, t_map_data *m_d)
{
	int				fd;
	t_list_split	*l_s;

	l_s = (t_list_split *)malloc(sizeof(t_list_split));
	if (l_s == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	fd = open(argv, O_RDONLY, 0);
	if (fd < 0)
	{
		close(fd);
		ft_exit(FD_ERROR);
	}
	read_file(fd, l_s, m_d);
	divide_height_colour(l_s, m_d);
	close(fd);
}
