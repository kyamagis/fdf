/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:11:25 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/30 19:44:25 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lendst(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = 0;
	if (dst != NULL)
		dstlen = ft_lendst(dst, dstsize);
	if (dstlen == dstsize)
		return (srclen + dstsize);
	ft_strlcpy(&dst[dstlen], src, dstsize - dstlen);
	return (dstlen + srclen);
}

/*int    main(void)
{
    char    dest[1024];
    char    dest2[1024];
    char    src[100] = "qJxqmoQXo_rfaerf";
    char    src2[100] = "WXVfadcfuJkx_rgae";
    char    src3[100] = "VtFQwLApiFWqdJEvFxp_dvsdfza";
    int        i;
    int        n;

    i = 0;
    n = 10;
    printf("src\n");
    printf("本家\n");
    i = strlcat(dest2, src, n);
    printf("%d\n", i);
    printf("%s\n", dest2);
    printf("自作\n");
    i = ft_strlcat(dest, src, n);
    printf("%d\n", i);
    printf("%s\n", dest);
    printf("\n");

    n = 10;
    printf("src2\n");
    printf("本家\n");
    i = strlcat(dest2, src2, n);
    printf("%d\n", i);
    printf("%s\n", dest2);
    printf("自作\n");
    i = ft_strlcat(dest, src2, n);
    printf("%d\n", i);
    printf("%s\n", dest);
    printf("\n");

    n = 100;
    printf("src3\n");
    printf("本家\n");
    i = strlcat(dest2, src3, n);
    printf("%d\n", i);
    printf("%s\n", dest2);
    printf("自作\n");
    i = ft_strlcat(dest, src3, n);
    printf("%d\n", i);
    printf("%s\n", dest);
    printf("\n");

    n = 10;
    printf("src4\n");
    printf("本家\n");
    //i = strlcat("6", 0, 0);
    printf("%d\n", i);
    printf("自作\n");
    //i = ft_strlcat("7", 0, 0);
    printf("%d\n", i);
    printf("\n");
    
    i = strlcat(0,"WORLD",0);
    printf("ORIGIN%d\n", i);
    i = ft_strlcat(NULL,"WORLD",0);
    printf("MAKEFT%d\n", i);
   
    i = strlcat("WORLD",0,0);
    printf("ORIGIN%d\n", i);
    i = ft_strlcat("WORLD",0,0);
    printf("MAKEFT%d\n", i);
    return (0);
}*/