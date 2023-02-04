/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:57:40 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/04 17:27:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	struct_to_tab(t_list *stack_a, t_data *data)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		data->tab[i] = stack_a->x;
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

void	node_num(t_data data)
{
	data.n = 1;
	if (data.node_num <= 10)
		data.n = 4;
	else if (data.node_num <= 150)
		data.n = 8;
	else if (data.node_num > 150)
		data.n = 16;
	data.m = data.node_num / 2;
}

void	small_swap(t_data data, t_list **stack_a)
{
	if (data.node_num == 2)
	{
		while (check_stack_a(*stack_a) == 0)
		{
			rr(stack_a);
			write(1, "rra\n", 3);
			printf("\n///////////////////\n");
			aff(*stack_a);
		}
	}
	else if (data.node_num == 3)
	{
		get_val(*stack_a, data);
	}
}

void	get_val(t_list *stack_a, t_data data)
{
	t_list	*tmp;
	int		max;

	tmp = stack_a;
	max = tmp->x;
	while (tmp->next)
	{
		if (tmp->x < (tmp->next)->x && tmp->index == -1)
			max = (tmp->next)->x;
		tmp = tmp->next;
	}
	while (stack_a)
	{
		if (stack_a->x == max)
		{
			stack_a->index = data.node_num;
			data.node_num--;
		}
		stack_a = stack_a->next;
	}
}
