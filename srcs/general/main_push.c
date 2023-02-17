/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/17 10:36:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	main_push(int ac, char **av)
{
	t_list	*stack_a;
	t_data	data;

	if (ac >= 2)
	{
		data.size_b = 0;
		stack_a = NULL;
		data.factor = 1;
		handl_arg(av, &data);
		data.size_a = data.node_num;
		fill_stack(&stack_a, data);
		free(data.tab);
		if (check_stack_a(stack_a) == 1)
			exit(0);
		get_val_end(&stack_a, &data);
		check_cases(stack_a, data);
		// system("leaks push_swap");
	}
	else
		write(1, "\n", 1);
}

void	check_cases(t_list *stack_a, t_data data)
{
	t_list	*stack_b;
	t_list	*down;

	stack_b = NULL;
	down = NULL;
	data.down = 0;
	if (data.node_num <= 5)
		small_swap(data, &stack_a);
	else
	{
		figure_para(&data, data.node_num);
		while (data.size_a != 0 && check_stack_a(stack_a) == 0)
		{
			push_swap(&data, &stack_a, &stack_b);
			data.factor++;
			figure_para(&data, data.node_num);
		}
		// aff(stack_b);
		while (data.size_b != 0)
		{
		// 	push_back(&data, &stack_b, &stack_a);
			get_out(&stack_b, &data, &stack_a, data.size_b);
		}
		aff(stack_a);
	}
	// system("leaks push_swap");
}

int	check_stack_a(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->x < stack_a->next->x)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

void	fill_stack(t_list **stack_a, t_data data)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < data.node_num)
	{
		new_node = ft_lstnew(data.tab[i]);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
