/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/13 19:52:11 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*t;

	tmp = *stack_a;
	while (data->size_a != 0 && check_index(stack_a, data->n) == 1)
	{
		if (tmp->index <= data->n)
		{
			write_p(stack_a, stack_b, "pb\n");
			data->size_a--;
			data->size_b++;
			tmp = *stack_a;
		}
		else if (tmp->index > data->n)
		{
			t = ft_lstlast(*stack_a);
			if (t->index <= data->n)
				write_rr(stack_a, "rra\n");
			else
				write_r(stack_a, "ra\n");
			tmp = *stack_a;
		}
	}
}

void	figure_para(t_data *data)
{
	if (data->size_a <= 10)
		data->n = 2;
	else if (data->size_a <= 150)
		data->n = 4;
	else if (data->size_a <= 500)
		data->n = 8;
	data->n = data->size_a / data->n * data->factor;
}

void	push_back(t_data *data, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == data->size_b)
		{
			printf("found\n");
			check_close(stack_b, data, stack_a);
			data->size_b--;
			tmp = *stack_b;
		}
		if (data->size_b == 1)
		{
			write_p(stack_b, stack_a, "pa\n");
			data->size_b--;
		}
		else
			tmp = tmp->next;
	}
}
