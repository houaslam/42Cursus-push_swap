/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/15 13:35:14 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_back(t_data *data, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (data->size_b != 0)
	{
		check_max(stack_b, data, stack_a);
	}
}

void	check_max(t_list **stack_b, t_data *data, t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		if (tmp->index == max_index(*stack_b))
		{
			if (i < data->size_b / 2)
				get_out_up_(stack_b, stack_a, data);
			else if (i >= data->size_b / 2)
				get_out_down_(stack_b, stack_a, data);
		}
		tmp = tmp->next;
		i++;
	}
}

void	get_out_up_(t_list **stack_b, t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index != max_index(*stack_b))
		{
			write_r(stack_b, "rb\n");
			tmp = *stack_b;
		}
		else
		{
			write_p(stack_b, stack_a, "pa\n");
			data->size_b--;
			return ;
		}
	}
}

void	get_out_down_(t_list **stack_b, t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index != max_index(*stack_b))
		{
			write_rr(stack_b, "rrb\n");
			tmp = *stack_b;
		}
		else
		{
			write_p(stack_b, stack_a, "pa\n");
			data->size_b--;
			return ;
		}
	}
}
