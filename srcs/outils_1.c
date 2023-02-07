/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/07 20:49:04 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    check_do(t_list **stack_a, t_data data)
{
    if((*stack_a)->index == data.node_num - 1 && (*stack_a)->next->index == data.node_num - 2 && (*stack_a)->next->next->index == data.node_num)
        write_s(stack_a, "sa ");
    else  if((*stack_a)->index == data.node_num && (*stack_a)->next->index == data.node_num - 1 && (*stack_a)->next->next->index == data.node_num - 2)
        {
            write_s(stack_a, "sa ");
            write_rr(stack_a, "rra ");
        }
    else  if((*stack_a)->index == data.node_num - 1 && (*stack_a)->next->index == data.node_num && (*stack_a)->next->next->index == data.node_num - 2)
            write_rr(stack_a, "rra ");
    else if((*stack_a)->index == data.node_num && (*stack_a)->next->index == data.node_num - 2 && (*stack_a)->next->next->index == data.node_num - 1)
            write_r(stack_a, "ra ");
    else if((*stack_a)->index == data.node_num - 2 && (*stack_a)->next->index == data.node_num && (*stack_a)->next->next->index == data.node_num - 1)
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
    *stack_b = NULL;
    get_val_end(&tmp, data);
    tmp = *stack_a;
    while(tmp)
    {
        if (tmp->index == 4)
        {
            // r(stack_a);
            p(stack_a, stack_b);
            printf("pb\n");
            data->node_num--;
        }
        tmp = tmp->next;
    }
    tmp = *stack_a;
    check_do(stack_a, *data);
    // aff(*stack_a);
    p(stack_b, stack_a);
    printf("pa\n");
    r(stack_a);
    printf("pa\n");
}