/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/10 15:56:25 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && data->size != 0)
	{
		if (tmp->index >= data->start && tmp->index <= data->end)
		{
			check_close(stack_a, data, stack_b, tmp->index);
			data->size--;
			tmp = *stack_a;
		}
		if (data->size == 1)
		{
			write_p(stack_a, stack_b, "pb\n");
			data->size--;
		}
		else
			tmp = tmp->next;
	}
	data->start = data->start - data->off;
	if (data->start < 0)
		data->start = 1;
	data->end = data->end + data->off;
	if (data->start > data->node_num)
		data->start = data->node_num;
}

void	figure_para(t_data *data)
{
	int	m;

	m = data->node_num / 2;
	if (data->node_num <= 10)
		data->n = 5;
	else if (data->node_num <= 150)
		data->n = 8;
	else if (data->node_num > 150)
		data->n = 18;
	data->off = data->node_num / data->n;
	data->start = m - data->off;
	data->end = m + data->off;
}

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
