/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:21:13 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/23 16:18:53 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst == NULL) || (new == NULL))
		return ;
	new->next = *lst;
	*lst = new;
}

/*int 	main(void)
{
	t_list **lst;
	t_list *new;
	
	new = (t_list *)malloc(sizeof(t_list));
	lst = (t_list **)malloc(sizeof(t_list));
	*lst = (t_list *)malloc(sizeof(t_list));
	new->content = "try";
	new->next = NULL;
	(*lst)->content = "touch down";
	printf("[newcontent]%s\n", (char *)new->content);
	printf("[newnext   ]%d\n", !!(char *)new->next);
	printf("[lstcontent]%s\n", (char *)(*lst)->content);
	printf("[lstnext   ]%d\n", !!(char *)(*lst)->next);
	printf("\n");
	ft_lstadd_front(lst, new);
	printf("[lstcontent]%s\n", (char *)(*lst)->content);
	printf("[lstnext   ]%d\n", !!(char *)(*lst)->next);
}*/
