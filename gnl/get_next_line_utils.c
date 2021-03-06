/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:47:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/16 13:01:59 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	size_t			i;
	unsigned char	*suc;
	unsigned char	cuc;

	if (s == NULL)
		return (NULL);
	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (suc[i] != '\0')
	{
		if (suc[i] == cuc)
			return ((char *)suc + i);
		i++;
	}
	if (cuc == '\0')
		return ((char *)suc + i);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	char	*castsrc;

	if (src == NULL)
	{
		dest[0] = '\0';
		return (0);
	}
	castsrc = (char *) src;
	lensrc = ft_strlen_gnl(src);
	if (size == 0)
		return (lensrc);
	i = 0;
	while (i < size - 1 && castsrc[i] != '\0')
	{
		dest[i] = castsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

char	*ft_free_str(char	*str, int discrim)
{
	if (discrim == NOMAL_END || discrim == CONTINUE)
	{
		free(str);
		str = NULL;
	}
	if (discrim == READ_ERROR)
	{
		write(2, READ_ERROR_MESSAGE, ft_strlen_gnl(READ_ERROR_MESSAGE));
		exit(1);
	}
	if (discrim == MALLOC_ERROR)
	{
		write(2, MALLOC_ERROR_MESSAGE, ft_strlen_gnl(MALLOC_ERROR_MESSAGE));
		exit(1);
	}
	return (str);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*prc;
	size_t	lens1;

	lens1 = 0;
	if (s1 != NULL)
		lens1 = ft_strlen_gnl(s1);
	prc = (char *)malloc(sizeof(char) * (lens1 + 1));
	if (prc == NULL)
		return (NULL);
	ft_strlcpy_gnl(prc, s1, lens1 + 1);
	return (prc);
}

/*int	main(void)
{
	char *str;
	//char *str1;
	t_data_buff	*outp_1;

	outp_1 = (t_data_buff *)malloc(sizeof(t_data_buff));
	outp_1->prefix = (char *)malloc(sizeof(char) * (4 + 1));
	outp_1->prefix = "GET_";
	outp_1->buff = (char *)malloc(sizeof(char) * (5 + 1));
	outp_1->buff = "WILD\n";
	ft_join_to_nl(outp_1);

	// ft_str_nl (outp_1, 0);
	// printf("%d\n", outp_1->null_flg);
	
	printf("prefix%s\n", outp_1->prefix);
	printf("buff  %s\n", outp_1->buff);
	printf("saved %s\n", outp_1->saved);
	printf("nl_flg%d\n", outp_1->newl_flag);
	
		printf("dup%s\n", ft_strdup(NULL));
	str = (char *)malloc(sizeof(char) * (5));
	str[0] = '1';
	printf("%s\n", str);
}*/