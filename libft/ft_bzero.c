/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:02:11 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/20 12:02:39 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*#include <stdio.h>
#include <strings.h>
int	main(void)
{
	char buf1[] = "ABCDEFGHIJK";
	char buf2[] = "ABCDEFGHIJK";
 
	bzero(buf1+2,3);
    printf("buf1文字列→%s\n",buf1);

	ft_bzero(buf2+2,3);
    printf("buf2文字列→%s\n",buf2);
}*/
