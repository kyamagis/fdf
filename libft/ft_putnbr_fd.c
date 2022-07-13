/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:58:24 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/04 22:26:12 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (-10 < n && n < 0)
		ft_putchar_fd('-', fd);
	if (n <= -10 || 10 <= n)
		ft_putnbr_fd(n / 10, fd);
	n = n % 10;
	if (n < 0)
		n *= -1;
	ft_putchar_fd('0' + n, fd);
}

/*int main (void)
{
	printf("[ 2147483647]");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
	printf("[-2147483648]");
	ft_putnbr_fd(-2147483649, 1);
	printf("\n");
	printf("[          0]");
	ft_putnbr_fd(0, 1);
	return (0);
}*/