/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:45:32 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/21 10:22:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	write_r(t_list **stack, char *str)
{
	if (ft_lstsize(*stack) >= 2)
	{
		r(stack);
		write(1, str, ft_strlen(str));
	}
	return ;
}

void	write_s(t_list **stack, char *str)
{
	if (ft_lstsize(*stack) >= 2)
	{
		s(stack);
		write(1, str, ft_strlen(str));
	}
	return ;
}

void	write_rr(t_list **stack, char *str)
{
	if (ft_lstsize(*stack) >= 2)
	{
		rr(stack);
		write(1, str, ft_strlen(str));
	}
	return ;
}

void	write_p(t_list **stack_2, t_list **stack, char *str)
{
	if (ft_lstsize(*stack_2) > 0)
	{
		p(stack_2, stack);
		write(1, str, ft_strlen(str));
	}
}
