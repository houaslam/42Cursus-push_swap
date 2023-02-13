/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/13 10:37:38 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_index(t_list **stack_a, int nb)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	get_back(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

void	check_close(t_list **stack_b, t_data *data, t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		if (tmp->index == data->size_b)
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
			return ;
		}
	}
}

void	get_out_down_b(t_list **stack_b, t_list **stack_a, t_data *data)
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
			return ;
		}
	}
}