/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:00:46 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/07 11:23:22 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*suc;
	unsigned char	cuc;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (suc[i] != '\0')
	{
		if (suc[i] == cuc)
			return ((char *)suc + i);
		i++;
	}
	if (cuc == '\0')
		return ((char *)suc + i);
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
	const char s[] = "abcdefghij";
	int c = 'c';
	int z = 'z';
	printf("本家%d\n" ,!!strchr("\0", -256));
	printf("自作%d\n\n" ,!!ft_strchr("\0", -256));

	printf("本家%s\n" ,strchr(s, z));
	printf("自作%s\n\n" ,ft_strchr(s, z));

	printf("本家%s\n" ,strchr(s, 0));
	printf("自作%s\n\n" ,ft_strchr(s, 0));

	printf("Difference: %d\n",(int) (strchr(s,c)-ft_strchr(s,c)));
}*/
