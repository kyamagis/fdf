/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:38:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/10 15:15:37 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lenhay;
	size_t	lennee;

	if (haystack == NULL)
		return (NULL);
	lenhay = ft_strlen(haystack);
	lennee = ft_strlen(needle);
	if (lenhay < lennee || len < lennee)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i + lennee <= len && i <= lenhay - lennee)
	{
		if (ft_strncmp(&haystack[i], needle, lennee) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	//const char	str[] = "Hellow!";
	//const char	to_find[] = "loi";

	//printf("a%s\n", strnstr(NULL, NULL,0));
	printf("%s\n", strnstr("ab", "a",4));
	printf("%s\n", ft_strnstr("ab", "a",4));
	// printf("%s\n", strnstr(str, to_find, 20));
	// printf("%s\n", ft_strnstr(str, to_find, 20));
	// printf("%s\n", strnstr("", to_find,0));
	// printf("%s\n", ft_strnstr("", to_find,0));
	// printf("%s\n", strnstr("", "",0));
	// printf("%s\n", ft_strnstr("", "",0));

	// printf("\n");

	// printf("origin%s\n", strnstr(NULL, "2", 0));
	// printf("makeft%s\n", ft_strnstr(NULL, "2", 0));
}*/