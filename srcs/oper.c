/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:17:09 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/04 15:16:39 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rr(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*t;

	tmp = *stack_a;
	t = ft_lstlast(tmp);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_front(stack_a, t);
}
