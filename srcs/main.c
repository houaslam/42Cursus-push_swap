/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/11 08:39:18 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	t_list	*tmp;

	if (ac >= 2)
	{
		stack_b = NULL;
		stack_a = NULL;
		data.tab = malloc(sizeof(int) * (ac - 1));
		handl_arg(av, &data);
		data.size = data.node_num;
		data.i = data.node_num;
		fill_stack(&stack_a, data);
		free(data.tab);
		check_stack_a(stack_a);
		get_val_end(&stack_a, &data);
		tmp = stack_a;
		if (data.node_num <= 5)
			small_swap(data, &tmp);
		else
		{
			figure_para(&data);
			while (stack_a)
				push_swap(&data, &stack_a, &stack_b);
			// while (stack_b)
			// 	push_back(&data, &stack_b, &stack_a);
		}
		// aff(stack_a);
	}
	else
		write(1, "Error\n", 6);
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

void	push_back(t_data *data, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == data->i)
		{
			check_close(stack_b, data, stack_a, data->i);
			data->i--;
			tmp = *stack_b;
		}
		else if (data->size == 1)
		{
			write_p(stack_b, stack_a, "pa\n");
			data->size--;
		}
		else
			tmp = tmp->next;
	}
}
