/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:38:43 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 12:54:43 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dis_max_min(unsigned long num, int flag)
{
	if (flag == 1 && 10000 <= num)
		exit(1);
	if (flag == -1 && 10000 <= num)
		exit(1);
	return ((int)(num * flag));
}

int	ft_atoi(const char *str)
{
	unsigned long	num;
	size_t			i;
	int				flag;
	size_t			digcount;

	flag = 1;
	num = 0;
	i = 0;
	digcount = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (num != 0)
			digcount++;
		if (4 < digcount)
			exit(1);
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (ft_dis_max_min(num, flag));
}

/*int	main(void)
{
	char	src[] = "";
	char	src2[] = "--1234ab567";
	char	src3[] = "5678VtFQwLApiFWqdJEvFxp_dvsdfza";
	char	src4[] = "abc1234";
	char	src5[] = " +1+1234ab567";
	char	src6[] = " -1+1234ab567";
	char	src7[] = "+-1234ab567";
	char	src8[] = " \f\n\r\t\v1234ab567";
	char	src9[] = " \f\n1\r\t\v1234ab567";
	char	src10[] = " \f\n-\r\t\v1234ab567";
	char	src11[] = " \f\n-1\r\t\v1234ab567";
	char	src12[] = "2247483648";
	char	src13[] = "9223372036854775806";
	char	src14[] = "18446744073709551613";
	char	src15[] = "18446744073709551616";
	char	src16[] = "36893488147419103232";
	char    src17[] = "63410682753376583680";
	char    src18[] = "000000000000000000008";
	char    src19[] = "9223372036854775808";
	int		i;

	i = 0;
	i = atoi(src);
	printf("本家:%d\n", i);
	i = ft_atoi(src);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src2);
	printf("本家:%d\n", i);
	i = ft_atoi(src2);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src3);
	printf("本家:%d\n", i);
	i = ft_atoi(src3);
	printf("自作:%d\n", i);
	printf("\n");
	
	i = atoi(src4);
	printf("本家:%d\n", i);
	i = ft_atoi(src4);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src5);
	printf("本家:%d\n", i);
	i = ft_atoi(src5);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src6);
	printf("本家:%d\n", i);
	i = ft_atoi(src6);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src7);
	printf("本家:%d\n", i);
	i = ft_atoi(src7);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src8);
	printf("本家:%d\n", i);
	i = ft_atoi(src8);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src9);
	printf("本家:%d\n", i);
	i = ft_atoi(src9);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src10);
	printf("本家:%d\n", i);
	i = ft_atoi(src10);
	printf("自作:%d\n", i);
	printf("\n");

	i = atoi(src11);
	printf("本家:%d\n", i);
	i = ft_atoi(src11);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src12);
	i = atoi(src12);
	printf("本家:%d\n", i);
	i = ft_atoi(src12);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src13);
	i = atoi(src13);
	printf("本家:%d\n", i);
	i = ft_atoi(src13);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src14);
	i = atoi(src14);
	printf("本家:%d\n", i);
	i = ft_atoi(src14);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src15);
	i = atoi(src15);
	printf("本家:%d\n", i);
	i = ft_atoi(src15);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src16);
	i = atoi(src16);
	printf("本家:%d\n", i);
	i = ft_atoi(src16);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src17);
	i = atoi(src17);
	printf("本家:%d\n", i);
	i = ft_atoi(src17);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src18);
	i = atoi(src18);
	printf("本家:%d\n", i);
	i = ft_atoi(src18);
	printf("自作:%d\n", i);
	printf("\n");

	printf("%s\n", src19);
	i = atoi(src19);
	printf("本家:%d\n", i);
	i = ft_atoi(src19);
	printf("自作:%d\n", i);
	printf("\n");
}*/