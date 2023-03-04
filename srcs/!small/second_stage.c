/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/19 20:42:35 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_out(t_list **stack_b, t_data *data, t_list **stack_a, int ind)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_b;
	last = ft_lstlast(*stack_a);
	if (ind < 0 && data->down != 0)
	{
		write_rr(stack_a, "rra\n");
		data->k--;
		data->down--;
	}
	else if (data->down > 0 && last && tmp->index == last->index + 1)
	{
		write_p(stack_b, stack_a, "pa\n");
		write_r(stack_a, "ra\n");
		data->size_b--;
		data->down++;
	}
	else
	{
		if (ind < data->size_b / 2)
			write_r(stack_b, "rb\n");
		else
			write_rr(stack_b, "rrb\n");
	}
}

void	push_back(t_data *data, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;
	int		ind;

	tmp = *stack_b;
	last = ft_lstlast(*stack_a);
	ind = search_in_sb(stack_b, data->k);
	if (tmp->index == data->k)
	{
		write_p(stack_b, stack_a, "pa\n");
		data->size_b--;
		data->k--;
	}
	else if (data->down == 0)
	{
		write_p(stack_b, stack_a, "pa\n");
		write_r(stack_a, "ra\n");
		data->size_b--;
		data->down++;
	}
	else
		get_out(stack_b, data, stack_a, ind);
}
