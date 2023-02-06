/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:57:40 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/06 01:48:09 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	struct_to_tab(t_list *stack_a, t_data *data)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		// data->tab[i] = stack_a->x;
		i++;
		stack_a = stack_a->next;
	}
}

void	fill_stack(t_list **stack_a, char **av)
{
	t_list	*new_node;
	int		i;

	i = 1;
	while (av[i] != NULL)
	{
		new_node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}

// void	node_num(t_data data)
// {
// 	data.n = 1;
// 	if (data.node_num <= 10)
// 		data.n = 4;
// 	else if (data.node_num <= 150)
// 		data.n = 8;
// 	else if (data.node_num > 150)
// 		data.n = 16;
// 	data.m = data.node_num / 2;
// }

void	small_swap(t_data data, t_list **stack_a)
{
	if (data.node_num == 2)
	{
		while (check_stack_a(*stack_a) == 0)
		{
			rr(stack_a);
			write(1, "rra\n", 3);
		}
	}
	else if (data.node_num == 3)
	{
		get_val_end(stack_a, &data);
		check_do(stack_a);
	}
	else if (data.node_num == 4)
		only_four(stack_a, &data);
}

void	get_val(t_list **stack_a, t_data *data)
{
	int		max;
	t_list *tmp;

	tmp = *stack_a;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->x > max && tmp->index == -1)
			max = tmp->x;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->x == max && tmp->index == -1)
		{
			tmp->index = data->node_num;
			data->node_num--;
		}
		tmp = tmp->next;
	}
}

void	get_val_end(t_list	**stack_a, t_data *data)
{
	int k;
	k = data->node_num;
		while(k > 0)
			{
				get_val(stack_a, data);
				k--;
			}
}
