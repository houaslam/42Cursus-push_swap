/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/09 20:45:39 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_do(t_list **stack_a, t_data data)
{
	if ((*stack_a)->index == data.node_num - 1 && (*stack_a)->\
	next->index == data.node_num - 2 && \
	(*stack_a)->next->next->index == data.node_num)
		write_s(stack_a, "sa\n");
	else if ((*stack_a)->index == data.node_num && (*stack_a)->\
	next->index == data.node_num - 1 && \
	(*stack_a)->next->next->index == data.node_num - 2)
	{
		write_s(stack_a, "sa\n");
		write_rr(stack_a, "rra \n");
	}
	else if ((*stack_a)->index == data.node_num \
	- 1 && (*stack_a)->next->index == data.node_num \
	&& (*stack_a)->next->next->index == data.node_num - 2)
		write_rr(stack_a, "rra\n");
	else if ((*stack_a)->index == data.node_num && \
	(*stack_a)-> next->index == data.node_num - 2 && \
	(*stack_a)->next->next->index == data.node_num - 1)
		write_r(stack_a, "ra\n");
	else if ((*stack_a)->index == data.node_num - 2 && \
	(*stack_a)->next->index == data.node_num && \
	(*stack_a)->next->next->index == data.node_num - 1)
	{
		write_s(stack_a, "sa\n");
		write_r(stack_a, "ra\n");
	}
}

void	only_four(t_list **stack_a, t_data *data, int nb)
{
	t_list	*tmp;
	t_list	*stack_b;

	tmp = *stack_a;
	stack_b = NULL;
	get_val_end(&tmp, data);
	tmp = *stack_a;
	check_close(stack_a, data, &stack_b, nb);
	check_do(stack_a, *data);
	write_p(&stack_b, stack_a, "pa\n");
}

void	check_close(t_list **stack_a, t_data *data, t_list **stack_b, int nb)
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
		tmp = *stack_a;
		if (tmp->index != nb)
			write_r(stack_a, "ra\n");
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
		tmp = *stack_a;
		if (tmp->index != nb)
			write_rr(stack_a, "rra\n");
		else
		{
			write_p(stack_a, stack_b, "pb\n");
			return ;
		}
	}
}
