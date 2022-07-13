/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:10:52 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/31 12:59:24 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*suc1;
	const unsigned char	*suc2;

	if (n == 0)
		return (0);
	suc1 = (const unsigned char *)s1;
	suc2 = (const unsigned char *)s2;
	i = 0;
	while ((i < n - 1) && ((suc1[i] - suc2[i]) == 0))
	{
		i++;
	}
	return (suc1[i] - suc2[i]);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	size_t	n = 3;
	const char s1m[] = "ABAE" ;
	const char s2m[] = "ABZJE";
	const char s10[] = "ABC" ;
	const char s20[] = "ABC";
	const char s1p[] = "ABCDE" ;
	const char s2p[] = "ABB";
	const char s1nul[] = "AB\0CDE" ;
	const char s2nul[] = "ABC";

	printf("本家%d\n", memcmp(s1m, s2m, n));
	printf("自作%d\n\n", ft_memcmp(s1m, s2m, n));

	printf("本家%d\n", memcmp(s10, s20, n));
	printf("自作%d\n\n", ft_memcmp(s10, s20, n));

	printf("本家%d\n", memcmp(s1p, s2p, n));
	printf("自作%d\n\n", ft_memcmp(s1p, s2p, n));

	printf("本家%d\n", memcmp(s1nul, s2nul, n));
	printf("自作%d\n\n", ft_memcmp(s1nul, s2nul, n));

	printf("本家%d\n", memcmp(s1nul, s2nul, n + 1));
	printf("自作%d\n\n", ft_memcmp(s1nul, s2nul, n + 1));

}*/