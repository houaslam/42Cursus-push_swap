/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/20 13:52:21 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	main(int ac, char **av)
{
	char	*hold;
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	if (ac >= 2)
	{
		stack_b = NULL;
		stack_a = NULL;
		handl_arg(av, &data);
		data.size_a = data.node_num;
		fill_stack(&stack_a, data);
		while (1)
		{
			hold = get_next_line(0);
			if (!hold)
				break ;
			compare_exec(hold, stack_a, stack_b);
			free(hold);
		}
		aff(stack_a);
		aff(stack_b);
		if (check_stack_a(stack_a) == 1 && ft_lstsize(stack_b) == 0)
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
}	

void	compare_exec(char *src, t_list	*stack_a, t_list *stack_b)
{
	if (ft_strncmp(src, "pa\n", 2) == 0)
		p(&stack_a, &stack_b);
	else if (ft_strncmp(src, "pb\n", 2) == 0)
		p(&stack_b, &stack_a);
	else if (ft_strncmp(src, "ra\n", 2) == 0)
		r(&stack_a);
	else if (ft_strncmp(src, "rb\n", 2) == 0)
		r(&stack_b);
	else if (ft_strncmp(src, "rra\n", 3) == 0)
		rr(&stack_a);
	else if (ft_strncmp(src, "rrb\n", 3) == 0)
		rr(&stack_b);
	else if (ft_strncmp(src, "sa\n", 2) == 0)
		s(&stack_a);
	else if (ft_strncmp(src, "sb\n", 2) == 0)
		s(&stack_b);
	else
		ft_putstr_fd("Error\n", 2);
}
