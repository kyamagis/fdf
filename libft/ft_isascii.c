/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:05:57 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/25 09:48:52 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((0x00 <= c) && (c <= 0x7F));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isascii('a'));
	printf("%d", ft_isascii('A'));
	printf("%d", ft_isascii('1'));
	printf("%d", ft_isascii('~'));
	return (0);
}*/