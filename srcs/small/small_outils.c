/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:34:44 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/20 14:47:45 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_do(t_list **stack_a)
{
	int	max;
	int	min;
	int	mid;

	max = max_index(*stack_a);
	min = min_index(*stack_a);
	mid = mid_index(*stack_a, max, min);
	if ((*stack_a)->index == mid && (*stack_a)->next->index == min \
	&& (*stack_a)->next->next->index == max)
		write_s(stack_a, "sa\n");
	else if ((*stack_a)->index == max && (*stack_a)->next->index == mid && \
	(*stack_a)->next->next->index == min)
	{
		write_s(stack_a, "sa\n");
		write_rr(stack_a, "rra\n");
	}
	check_do_2(stack_a, mid, max, min);
}

void	check_do_2(t_list **stack_a, int mid, int max, int min)
{
	if ((*stack_a)->index == mid && (*stack_a)->next->index == max \
	&& (*stack_a)->next->next->index == min)
		write_rr(stack_a, "rra\n");
	else if ((*stack_a)->index == max && (*stack_a)-> next->index == min && \
	(*stack_a)->next->next->index == mid)
		write_r(stack_a, "ra\n");
	else if ((*stack_a)->index == min && (*stack_a)->next->index == max \
	&& (*stack_a)->next->next->index == mid)
	{
		write_s(stack_a, "sa\n");
		write_r(stack_a, "ra\n");
	}
}

void	check_close_s(t_list **stack_a, t_data *data, t_list **stack_b, int nb)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->index == nb)
		{
			if (i < data->node_num / 2)
				get_out_up(stack_a, stack_b, nb);
			else if (i >= data->node_num / 2)
				get_out_down(stack_a, stack_b, nb);
		}
		tmp = tmp->next;
		i++;
	}
}

void	get_out_up(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index != nb)
		{
			write_r(stack_a, "ra\n");
			tmp = *stack_a;
		}
		else
		{
			write_p(stack_a, stack_b, "pb\n");
			return ;
		}
	}
}

void	get_out_down(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index != nb)
		{
			write_rr(stack_a, "rra\n");
			tmp = *stack_a;
		}
		else
		{
			write_p(stack_a, stack_b, "pb\n");
			return ;
		}
	}
}
