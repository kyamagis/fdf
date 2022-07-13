/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:14:45 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/07 11:25:21 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*suc1;
	const unsigned char	*suc2;

	suc1 = (const unsigned char *)s1;
	suc2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((i < n - 1) && ((suc1[i] - suc2[i]) == 0) \
	&& (suc1[i] != '\0') && (suc2[i] != '\0'))
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

	printf("本家%d\n", strncmp(s1m, s2m, n));
	printf("自作%d\n\n", ft_strncmp(s1m, s2m, n));

	printf("本家%d\n", strncmp(s10, s20, n));
	printf("自作%d\n\n", ft_strncmp(s10, s20, n));

	printf("本家%d\n", strncmp(s1p, s2p, n));
	printf("自作%d\n", ft_strncmp(s1p, s2p, n));
}*/
