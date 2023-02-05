/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/05 21:37:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    check_do(t_list **stack_a)
{
    if((*stack_a)->index == 2 && (*stack_a)->next->index == 1 && (*stack_a)->next->next->index == 3)
       {
            s(*stack_a);
            write(1, "sa", 3);
       }
    else  if((*stack_a)->index == 3 && (*stack_a)->next->index == 2 && (*stack_a)->next->next->index == 1)
        {
            s(*stack_a);
            rr(stack_a);
            write(1, "sa rra", 6);
        }
    else  if((*stack_a)->index == 2 && (*stack_a)->next->index == 3 && (*stack_a)->next->next->index == 1)
        {
           rr(stack_a);
           write(1, "rra ", 4);
        }
    else if((*stack_a)->index == 3 && (*stack_a)->next->index == 1 && (*stack_a)->next->next->index == 2)
        {
            r(stack_a);
            write(1, "ra ", 3);
        }
    else if((*stack_a)->index == 1 && (*stack_a)->next->index == 3 && (*stack_a)->next->next->index == 2)
        {
            s(*stack_a);
            r(stack_a);
            write(1, "sa ra", 6);
        }
}
