/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:04:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/25 14:30:46 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100000
# define MALLOC_ERROR -2
# define READ_ERROR -1
# define NOMAL_END 0
# define CONTINUE  1
# define READ_ERROR_MESSAGE "Read Error\n"
# define MALLOC_ERROR_MESSAGE "Malloc Error\n"

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dest, char *src, size_t size);
char	*ft_free_str(char	*str, int discrim);
char	*ft_strdup_gnl(char *s1);
#endif
