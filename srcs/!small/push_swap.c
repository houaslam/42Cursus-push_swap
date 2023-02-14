/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/14 13:42:22 by houaslam         ###   ########.fr       */
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

void	figure_para(t_data *data, int size)
{
	if (size == 1)
		data->n = 1;
	else if (size <= 10)
		data->n = 2;
	else if (size <= 150)
		data->n = 4;
	else if (size <= 500)
		data->n = 6;
	data->n = size / data->n * data->factor;
}

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
		if (tmp->index == data->size_b)
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
		if (tmp->index != data->size_b)
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
		if (tmp->index != data->size_b)
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
