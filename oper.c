/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:17:09 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/12 18:34:04 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list *stack_a)
{
	int	tmp;

	if (ft_lstsize(stack_a) >= 2)
	{
		tmp = stack_a->x;
		stack_a->x = stack_a->next->x;
		stack_a->next->x = tmp;
	}
}

void	p(t_list **stack_a, t_list *stack_b)
{
	if (ft_lstsize(*stack_a) > 0)
		ft_lstadd_front(stack_a, stack_b);
}
