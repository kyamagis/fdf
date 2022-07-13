/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:31:34 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/30 20:02:10 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	char	*castsrc;

	castsrc = (char *) src;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	i = 0;
	while (i < size - 1 && castsrc[i] != '\0')
	{
		dest[i] = castsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

/*
void ft_putisnull(char *str, int size)
{
    int    i;
    char c;

    i = 0;
    while (i < size)
    {
        c = '0' + (str[i] == '\0');
        write (1, &c, 1);
        i++;
    }

}
int	main(void)
{
	char	dest[100] = "dos";
	char	src[] = "Hellow";
	unsigned int	size = 5;

	printf("%s\n", dest);

	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	ft_putisnull(dest, 10);
	
	printf("\n");
	printf("%lu\n", strlcpy(dest, src, size));
	printf("%s\n", dest);
	ft_putisnull(dest, 10);

	char	dest2[100] = "dos";
	char	src2[] = "Hellow";

	printf("\n");
	printf("%lu\n", strlcpy(dest2, src2, 0));
	printf("%s\n", dest2);
	ft_putisnull(dest2, 10);

	printf("\n");
	printf("%zu\n", ft_strlcpy(dest2, src2, 0));
	printf("%s\n", dest2);
	ft_putisnull(dest2, 10);
	
	return (0);
}*/
