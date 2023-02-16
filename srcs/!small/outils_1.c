/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/16 13:26:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_index(t_list **stack_a, int end, int start)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_close(t_list **stack_b, t_data *data, t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	(void)data;
	i = 0;
	while (tmp)
	{
		if (tmp->index == max_index(*stack_b))
		{
			if (i < data->node_num / 2)
				get_out_up_b(stack_b, stack_a, data);
			else if (i >= data->node_num / 2)
				get_out_down_b(stack_b, stack_a, data);
		}
		tmp = tmp->next;
		i++;
	}
}

void	get_out_up_b(t_list **stack_b, t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	tmp = *stack_a;
	(void)data;
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
			return ;
		}
	}
}

void	get_out_down_b(t_list **stack_b, t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	tmp = *stack_b;
	(void)data;
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
			return ;
		}
	}
}

// void	second_max(t_list **stack_a)
// {
	
// }