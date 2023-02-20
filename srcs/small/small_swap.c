/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:57:40 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/20 14:33:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	small_swap(t_data data, t_list **stack_a)
{
	if (data.node_num == 2)
	{
		while (check_stack_a(*stack_a) == 0)
		{
			rr(stack_a);
			write(1, "rra\n", 3);
		}
	}
	else if (data.node_num == 3)
		check_do(stack_a);
	// else if (data.node_num == 4)
	// 	only_four(stack_a, &data, 1);
	// else if (data.node_num == 5)
	// 	only_five(stack_a, &data);
	//system ("leaks push_swap");
}

void	get_val(t_list **stack_a, t_data *data)
{
	int		max;
	t_list	*tmp;

	tmp = *stack_a;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->x > max && tmp->index == -1)
			max = tmp->x;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->x == max && tmp->index == -1)
		{
			tmp->index = data->size_a;
			data->size_a--;
		}
		tmp = tmp->next;
	}
}

void	get_val_end(t_list	**stack_a, t_data *data)
{
	int	k;
	int	j;

	j = data->size_a;
	k = data->size_a;
	while (k > 0)
	{
		get_val(stack_a, data);
		k--;
	}
	data->size_a = j;
}

void	only_four(t_list **stack_a, t_data *data, int nb)
{
	t_list	*tmp;
	t_list	*stack_b;

	(void)nb;
	tmp = *stack_a;
	stack_b = NULL;
	get_val_end(&tmp, data);
	tmp = *stack_a;
	check_close_s(stack_a, data, &stack_b, nb);
	check_do(stack_a);
	write_p(&stack_b, stack_a, "pa\n");
}

void	only_five(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	t_list	*stack_b;

	tmp = *stack_a;
	stack_b = NULL;
	get_val_end(&tmp, data);
	tmp = *stack_a;
	check_close_s(stack_a, data, &stack_b, 1);
	check_close_s(stack_a, data, &stack_b, 2);
	check_do(stack_a);
	write_p(&stack_b, stack_a, "pa\n");
	write_p(&stack_b, stack_a, "pa\n");
}
