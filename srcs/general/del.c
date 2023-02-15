/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:06:52 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/14 17:48:24 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	aff1(int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		printf("-**>%d\n", tab[i]);
		i++;
	}
}

void	aff(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("----> %d\n", tmp->x);
		printf("> %d\n", tmp->index);
		tmp = tmp->next;
	}
	printf("/////\n");
}
