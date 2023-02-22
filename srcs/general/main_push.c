/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/22 13:43:10 by houaslam         ###   ########.fr       */
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
		fill_stack(&stack_a, &data);
		get_val_end(&stack_a, &data);
		if (check_stack_a(stack_a) == 1)
			exit(0);
		data.node_num = data.size_a;
		check_cases(&stack_a, data);
	}
}

void	check_cases(t_list **stack_a, t_data data)
{
	t_list	*stack_b;

	stack_b = NULL;
	data.down = 0;
	if (data.size_a <= 5)
		small_swap(data, stack_a);
	else
	{
		figure_para(&data, data.size_a);
		while (data.size_a != 0)
		{
			push_swap(&data, stack_a, &stack_b);
			figure_para(&data, data.node_num);
		}
		data.k = data.size_b;
		while (data.size_b != 0)
			push_back(&data, &stack_b, stack_a);
		while (data.down > 0)
		{
			write_rr(stack_a, "rra\n");
			data.down--;
		}
	}
}

int	check_stack_a(t_list *stack_a)
{
	t_list	*tmp;

	if (!stack_a)
		return (0);
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->index < tmp->next->index)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	fill_stack(t_list **stack_a, t_data *data)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < data->size_a)
	{
		new_node = ft_lstnew(data->tab[i]);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
