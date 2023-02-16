/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/16 16:14:50 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	fastest_way_out(t_list **stack_b, t_data *data)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	data->max = -1;
	data->max_2 = -1;
	while (tmp)
	{
		if (tmp->index == max_index(*stack_b))
		{
			data->max = i;
			// printf("***%d\n", i);
		}
		else if (tmp->index == max_index(*stack_b) - 1)
		{
			data->max_2 = i;
			// printf("*2*%d\n", i);
		}
		tmp = tmp->next;
		i++;
	}
	// printf("----%d\n", data->size_b);
	// aff(*stack_b);
	// sleep(2);
	// if (data->max == -1 || data->max_2 == -1)
	// 	return (2);
	if (data->middle - data->max < data->middle - data->max_2)
		return (0);
	else
		return (1);
}

void	get_out(t_list **stack_b, t_data *data, t_list **stack_a, int res)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		if (tmp->index == res)
		{
			if (i < data->size_b / 2)
				get_out_up_(stack_b, stack_a, data, res);
			else if (i >= data->size_b / 2)
				get_out_down_(stack_b, stack_a, data, res);
		}
		tmp = tmp->next;
		i++;
	}
}

void	get_out_up_(t_list **stack_b, t_list **stack_a, t_data *data, int nb)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index != nb)
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

void	get_out_down_(t_list **stack_b, t_list **stack_a, t_data *data, int nb)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index != nb)
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

void	push_back(t_data *data, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		max;

	tmp = *stack_b;
	while (tmp)
	{
		if ()
	}
}
