/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:47:07 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/12 12:54:18 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	tmp = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (newlst);
}

/*void	ft_putstr(void *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s)
	{
		write (1, &s[i], 1);
		i++;
	}
}
void	*f(void *b)
{
	unsigned char	*bb;
	size_t			i;

	bb = (unsigned char *)b;
	i = 0;
	while (bb != '\0')
	{
		bb[i] = '0';
		bb++;
	}
	return (bb);
}
int main(void)
{
	printf("6\n");
	t_list *lst;
	char s[] = "000";
	printf("6\n");
	//printf("6%s", ft_mem(s));
	ft_lstmap(lst, f, ft_putstr);
}*/