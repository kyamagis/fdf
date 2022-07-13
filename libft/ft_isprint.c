/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:34:50 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/25 09:50:15 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return ((' ' <= c) && (c <= '~'));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isprint('a'));
	printf("%d", ft_isprint('A'));
	printf("%d", ft_isprint('1'));
	printf("%d", ft_isprint('~'));
	return (0);
}*/