/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:36:54 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/20 14:35:16 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	max_index(t_list *stack_a)
{
	t_list	*tmp;
	int		max;

	max = -1;
	tmp = stack_a;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	free (tmp);
	return (max);
}

int	min_index(t_list *stack_a)
{
	t_list	*tmp;
	int		min;

	min = INT_MAX;
	tmp = stack_a;
	while (tmp)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	mid_index(t_list *stack_a, int max, int min)
{
	t_list	*tmp;
	int		mid;

	mid = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index != max && tmp->index != min)
			mid = tmp->index;
		tmp = tmp->next;
	}
	return (mid);
}
