/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/14 13:15:12 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	main_push(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	t_list	*tmp;

	if (ac >= 2)
	{
		data.size_b = 0;
		stack_b = NULL;
		stack_a = NULL;
		data.factor = 1;
		handl_arg(av, &data);
		data.size_a = data.node_num;
		fill_stack(&stack_a, data);
		free(data.tab);
		check_stack_a(stack_a);
		get_val_end(&stack_a, &data);
		tmp = stack_a;
		if (data.node_num <= 5)
			small_swap(data, &tmp);
		else
		{
			figure_para(&data, data.size_a);
			while (data.size_a != 0)
			{
				push_swap(&data, &stack_a, &stack_b);
				data.factor++;
				figure_para(&data, data.size_a);
			}
			while (data.size_b != 0)
				push_back(&data, &stack_b, &stack_a);
		}
		// aff(stack_a);
	}
	else
		write(1, "\n", 1);
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
	exit(0);
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
