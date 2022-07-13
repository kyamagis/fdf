/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:08:31 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/27 19:58:50 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (unsigned char *) malloc(sizeof(unsigned char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}

/*char ft_repeat(unsigned int idx, char c)
{
	while (0 < idx)
	{
		c += 3;
		idx--;
	}
	return (c);
}
int	main(void)
{
	char str[] = "0000";
	printf("%s",ft_strmapi(str, ft_repeat));
}*/