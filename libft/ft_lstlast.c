/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:06:26 by kyamagis          #+#    #+#             */
/*   Updated: 2022/04/23 16:19:18 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int main(void)
{
	t_list	*s;
	t_list	*x;
	t_list	*y;
	t_list	*z;

	s = (t_list *)malloc(sizeof(t_list));
	x = (t_list *)malloc(sizeof(t_list));
	y = (t_list *)malloc(sizeof(t_list));
	z = (t_list *)malloc(sizeof(t_list));

	s->next = x;
	x->next = y;
	y->next = z;
	z->next = NULL;

	s->content = "We are X";
	z->content = "We are X";
	printf("%s\n", (char *)ft_lstlast(s)->next);
	printf("%s", (char *)ft_lstlast(s)->content);
}*/