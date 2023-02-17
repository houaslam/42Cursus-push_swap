/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/17 17:38:44 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_index(t_list **stack_a, int end, int start)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// void	check_close(t_list **stack_b, t_data *data, t_list **stack_a)
// {
// 	t_list	*tmp;
// 	int		i;

// 	tmp = *stack_b;
// 	(void)data;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (tmp->index == max_index(*stack_b))
// 		{
// 			if (i < data->node_num / 2)
// 				get_out_up_b(stack_b, stack_a, data);
// 			else if (i >= data->node_num / 2)
// 				get_out_down_b(stack_b, stack_a, data);
// 		}
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

int	search_in_sb(t_list **stack_b, int nb)
{
	t_list	*tmp;

	if (!*stack_b)
		return (0);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
