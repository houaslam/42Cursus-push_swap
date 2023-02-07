/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:17:09 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/07 20:37:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s(t_list **stack_a)
{
	int	tmp;
	int	a_tmp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		a_tmp = (*stack_a)->index;
		(*stack_a)->index = (*stack_a)->next->index;
		(*stack_a)->next->index = a_tmp;
		tmp = (*stack_a)->x;
		(*stack_a)->x = (*stack_a)->next->x;
		(*stack_a)->next->x = tmp;
	}
}

void	p(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
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

void	r(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*t;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	t = ft_lstlast(*stack_a);
	tmp->next = NULL;
	t->next = tmp;
}