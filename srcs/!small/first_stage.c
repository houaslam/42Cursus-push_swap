/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:45:39 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/19 20:41:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*t;

	tmp = *stack_a;
	while (check_index(stack_a, data->end, data->start) == 1)
	{
		if (tmp->index >= data->start && tmp->index <= data->end)
		{
			write_p(stack_a, stack_b, "pb\n");
			data->size_a--;
			data->size_b++;
			if (tmp->index <= data->middle && data->size_b >= 2)
				write_r(stack_b, "rb\n");
		}
		else
		{
			t = ft_lstlast(*stack_a);
			if (t->index >= data->start && t->index <= data->end)
				write_rr(stack_a, "rra\n");
			else
				write_r(stack_a, "ra\n");
		}
			tmp = *stack_a;
	}
	data->factor++;
}

void	figure_para(t_data *data, int size)
{
	if (size <= 10)
		data->n = 5;
	else if (size <= 150)
		data->n = 8;
	else if (size > 150)
		data->n = 18;
	data->middle = size / 2;
	data->offset = (size / data->n) * data->factor;
	data->start = data->middle - data->offset;
	data->end = data->middle + data->offset;
}
