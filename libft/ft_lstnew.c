/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:37:31 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/18 14:56:38 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (s == NULL)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}

/*int 	main(void)
{
	printf("%s\n", (char *)ft_lstnew("transam")->content);
	printf("%s\n", (char *)ft_lstnew("transam")->next);
}*/