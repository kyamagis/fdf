/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:38:52 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/03 15:16:23 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while ((*s1 != '\0') && (ft_strchr(set, *s1) != NULL))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while ((0 < len) && (ft_strchr(set, s1[len - 1]) != NULL))
		len--;
	return (ft_substr(s1, 0, len));
}

/*int	main(void)
{
	char const s1[] = "1232312323ABC1223DEF123";
	char const s2[] = "";
	char const set1[] = "123";
	char const set2[] = "GET_wild";

	printf("[12A123  ]%s\n", ft_strtrim(s1, set1));
	printf("[123GET_ ]%s\n", ft_strtrim(s1, set2));
	printf("[space123]%s\n", ft_strtrim(s2, set1));
	printf("[spacesp ]%s\n", ft_strtrim(s2, s2));
	printf("[spacent,]%s\n", ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t"));
	printf("[spsp    ]%s\n", ft_strtrim(s2, " \n\t"));
	printf("[]%s", s2);
}*/