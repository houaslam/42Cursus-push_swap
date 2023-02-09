/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:06:52 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/09 20:46:26 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (stack_a)
	{
		printf("----> %d\n", stack_a->x);
		// printf("> %d\n", stack_a->index);
		stack_a = stack_a->next;
	}
}
