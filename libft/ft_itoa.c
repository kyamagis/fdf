/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:34:37 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/12 11:08:51 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digcount(int n)
{
	size_t			dig;
	unsigned int	x;

	dig = 1;
	x = n;
	if (n < 0)
	{
		x = -n;
		dig = 2;
	}
	while (x >= 10)
	{
		x /= 10;
		dig++;
	}
	return (dig);
}

static unsigned char	*ft_int_to(size_t dig, unsigned char *str, int n)
{
	unsigned int	x;
	int				minus;

	x = n;
	minus = 0;
	if (n < 0)
	{
		x = -n ;
		minus = -1;
		str[0] = '-';
	}
	str[dig] = '\0';
	while (0 < dig + minus)
	{
		dig--;
		str[dig] = '0' + x % 10;
		x /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			dig;
	unsigned char	*str;

	dig = ft_digcount(n);
	str = (unsigned char *)malloc(sizeof(unsigned char) * (dig + 1));
	if (str == NULL)
		return (NULL);
	return ((char *)ft_int_to(dig, str, n));
}

/*int	main(void)
{
	printf("[ 2147483647] %s\n",ft_itoa(2147483647));
	printf("[-2147483648]%s\n",ft_itoa(-2147483648));
	printf("[          0]%s\n",ft_itoa(0));
	printf("[          9]%s\n",ft_itoa(9));
	return (0);
}*/