/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:50:38 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/22 13:01:31 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r_r(t_list **stack_a, t_list **stack_b)
{
	r(stack_b);
	r(stack_a);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	s(stack_b);
	s(stack_a);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rr(stack_b);
	rr(stack_a);
}
