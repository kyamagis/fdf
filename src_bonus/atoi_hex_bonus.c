/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:38:43 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/06 16:25:48 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static int	atoi_bit_shift(unsigned long num, size_t digcount)
{
	int	first_p;
	int	hexa_p;
	int	shift;

	shift = 0;
	first_p = num % 16;
	hexa_p = (num / 16) % 16;
	if (first_p != hexa_p)
		ft_exit(INVALID_COLOR_CODE);
	if (digcount == 4)
		while (shift++ < 2)
			num = num << 4 | +first_p;
	if (digcount == 2)
		while (shift++ < 4)
			num = num << 4 | +first_p;
	return ((int)(num));
}

static int	detect_abbreviation(unsigned long num, size_t digcount)
{
	if (digcount == 0 && num == 0)
		return ((int)(0xffffff));
	if (digcount == 2 || digcount == 4)
		return (atoi_bit_shift(num, digcount));
	if (digcount == 6)
		return ((int)(num));
	else
		ft_exit(INVALID_COLOR_CODE);
	return (0);
}

static int	ft_ishex(int c)
{
	return (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}

int	atoi_hex(const char *str)
{
	unsigned long	num;
	size_t			i;
	size_t			digcount;

	num = 0x0;
	i = 0;
	digcount = 0;
	while (str[i] != ',' && str[i] != '\0')
		i++;
	if (ft_strnstr(&str[i], ",0x", ft_strlen(",0x")))
	{
		i += 3;
		while (ft_ishex(str[i]))
		{
			if (ft_isdigit(str[i]))
				num = num * 16 + str[i] - '0';
			if ('a' <= str[i] && str[i] <= 'f')
				num = num * 16 + str[i] - 'a' + 10;
			if ('A' <= str[i] && str[i] <= 'F')
				num = num * 16 + str[i] - 'A' + 10;
			digcount++;
			i++;
		}
	}
	return (detect_abbreviation(num, digcount));
}

/*int	main(void)
{
	char	src[] = "abc,0x64";
	char	src2[] = "";
	char	src3[] = ",";
	char	src4[] = "0x";
	char	src5[] = ",0x-";
	char	src6[] = ",0xFFFFFFFFFFFFFFFFFFFFFF";
	char	src7[] = "1234,0x646464";
	char	src8[] = " ,0x0000ff";
	char	src9[] = " ,0xffee";
	char	src10[] = " ,0xff";
	char	src11[] = " \f\n-1\r\t\v1234ab567";
	char	src12[] = "abc,0x66";
	char	src13[] = "abc,0x008902";
	char	src14[] = "18446744073709551613";
	char	src15[] = "18446744073709551616";
	char	src16[] = "36893488147419103232";
	char    src17[] = "63410682753376583680";
	char    src18[] = "000000000000000000008";
	char    src19[] = "9223372036854775808";
	int		i;

	i = 0;

	printf("%s\n", src);
	i = atoi_hex(src);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src2);
	i = atoi_hex(src2);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src3);
	i = atoi_hex(src3);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");
	
	printf("%s\n", src4);
	i = atoi_hex(src4);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src5);
	i = atoi_hex(src5);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src6);
	i = atoi_hex(src6);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src7);
	i = atoi_hex(src7);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src8);
	i = atoi_hex(src8);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");


	printf("%s\n", src9);
	i = atoi_hex(src9);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	
	printf("%s\n", src10);
	i = atoi_hex(src10);
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	
	i = atoi_hex(src11);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src12);
	
	i = atoi_hex(src12);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src13);
	
	i = atoi_hex(src13);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src14);
	
	i = atoi_hex(src14);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src15);
	
	i = atoi_hex(src15);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src16);
	
	i = atoi_hex(src16);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src17);
	
	i = atoi_hex(src17);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src18);
	
	i = atoi_hex(src18);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");

	printf("%s\n", src19);
	
	i = atoi_hex(src19);
	
	printf("d:%d,x:%x\n", i, i);
	printf("\n");
}*/