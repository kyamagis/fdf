/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:29:14 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/27 20:01:07 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void ft_0to1(unsigned int idx, char *c)
{
	if (*c == '0')
		*c =  48 +idx;
}
int main(void)
{
	char str[] = "201010101010";
	ft_striteri(str, NULL);
	printf("%s\n",str);
	return (0);
}*/