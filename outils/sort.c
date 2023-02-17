/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:53:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/17 16:49:11 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	sort(int *tab, int size)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = j + 1;
// 	while (j < size)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (tab[j] < tab[i])
// 				swap(&tab[j], &tab[i]);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstnew(int i)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->x = i;
	node->next = NULL;
	return (node);
}
