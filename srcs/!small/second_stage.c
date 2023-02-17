/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:30:01 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/17 17:45:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	t_list *last;

	tmp = *stack_b;
	last = ft_lstlast(*stack_a);
	if (tmp->index == data->k)
	{
		write_p(stack_b, stack_a, "pa\n");
		data->size_b--;
		data->k--;
	}
	else if (search_in_sb(stack_b, data->k) == 0 && data->down != 0)
	{
		write_rr(stack_a, "rra\n");
		data->k--;
		data->down--;
	}
	else if (data->down == 0)
	{
		write_p(stack_b, stack_a, "pa\n");
		write_r(stack_a, "ra\n");
		data->size_b--;
		data->down++;
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
		get_out(stack_b, data, stack_a, data->k);
		data->k--;
	}
}
