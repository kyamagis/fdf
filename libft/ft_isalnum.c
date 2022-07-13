/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:46:49 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/25 10:00:10 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

/*int	main(void)
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('A'));
	printf("%d", ft_isalnum('1'));
	printf("%d", ft_isalnum('~'));
	return (0);
}*/