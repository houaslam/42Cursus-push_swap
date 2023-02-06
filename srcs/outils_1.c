/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/06 01:50:08 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    check_do(t_list **stack_a)
{
    if((*stack_a)->index == 2 && (*stack_a)->next->index == 1 && (*stack_a)->next->next->index == 3)
        write_s(stack_a, "sa ");
    else  if((*stack_a)->index == 3 && (*stack_a)->next->index == 2 && (*stack_a)->next->next->index == 1)
        {
            write_s(stack_a, "sa ");
            write_rr(stack_a, "rra ");
        }
    else  if((*stack_a)->index == 2 && (*stack_a)->next->index == 3 && (*stack_a)->next->next->index == 1)
            write_rr(stack_a, "rra ");
    else if((*stack_a)->index == 3 && (*stack_a)->next->index == 1 && (*stack_a)->next->next->index == 2)
            write_r(stack_a, "ra ");
    else if((*stack_a)->index == 1 && (*stack_a)->next->index == 3 && (*stack_a)->next->next->index == 2)
        {
            write_s(stack_a, "sa ");
            write_r(stack_a, "ra ");
        }
}

void    only_four(t_list **stack_a, t_data *data)
{
    t_list  *tmp;
    t_list  **stack_b;
    
    tmp = *stack_a;
    get_val_end(&tmp, data);
    tmp = *stack_a;
    // aff(tmp);
    while(tmp)
    {
        if (tmp->index == 4)
        {
            write_p(stack_a, stack_b, "pa ");
            printf("here\n");
            data->node_num--;
        }
        tmp = tmp->next;
    }
    tmp = *stack_a;
    check_do(stack_a);
    write_p(stack_b, stack_a, "pb ");
    
}