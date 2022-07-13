/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:31:06 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/03 15:24:55 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	if (len == SIZE_MAX)
		return (NULL);
	substr = (char *)malloc (sizeof (char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}

/*
char	*ft_putisnull(char const *str, size_t size)
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
int main(void)
{
	char const s[] = "ABCDEFGH";
	unsigned int start = 0;
	size_t len = 0;

	printf("[printsubstr]%s\n", ft_substr("tripouille", 100, 1));
	printf("[exchangesub]%d\n",!strcmp(ft_substr("tripouille", 100, 1), ""));
}*/
