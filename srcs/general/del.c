/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:06:52 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/16 13:47:05 by houaslam         ###   ########.fr       */
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

void	aff2(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	t_list	*tmpb;

	tmp = stack_a;
	tmpb = stack_b;
	while (1)
	{
		printf("|  %d    |\t|   %d  |\n", tmp->x, tmpb->x);
		printf("|> %d   |\t|>  %d  |", tmp->index, tmpb->index);
		if (tmp->next)
			tmp = tmp->next;
		if (tmpb->next)
			tmpb = tmpb->next;
		else if(!tmp->next && !tmpb->next)
			break ;
	}
	printf("____\t____\n");
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
