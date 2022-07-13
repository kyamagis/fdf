/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:52:38 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/07 19:49:28 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*addr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((SIZE_MAX / count) < size)
		return (NULL);
	addr = malloc(count * size);
	if (addr == NULL)
		return (NULL);
	ft_memset(addr, 0, count * size);
	return (addr);
}

/*char	*ft_putisnull(void *str, size_t size)
{
	size_t	i;
	char *addr;

	addr =(char *)str;
	i = 0;
	while (i < size)
	{
		if (addr[i] == '\0')
			addr[i] = '0';
		i++;
	}
	return (addr);
}
int	main(void)
{
	printf("[0, 0]%s\n", ft_putisnull(ft_calloc(0, 0), 2));
	printf("[2, 2]%s\n", ft_putisnull(ft_calloc(2, 2), 5));
	printf("[ULLONG_MAX, 2]%s\n", ft_calloc(ULLONG_MAX, 2));
	printf("[ULLONG_MAX, 2]%s\n", calloc(ULLONG_MAX, 2));
}*/