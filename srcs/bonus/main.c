/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/22 13:01:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	main(int ac, char **av)
{
	char	*hold;
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data_s;

	if (ac >= 2)
	{
		stack_b = NULL;
		stack_a = NULL;
		handl_arg(av, &data_s);
		data_s.size_a = data_s.node_num;
		fill_stack(&stack_a, &data_s);
		get_val_end(&stack_a, &data_s);
		while (1)
		{
			hold = get_next_line(0);
			if (!hold)
				break ;
			compare_exec(hold, &stack_a, &stack_b);
			free(hold);
		}
		ok_or_ko(&data_s, &stack_a);
	}
}	

void	compare_exec(char *src, t_list	**stack_a, t_list **stack_b)
{
	if (ft_strncmp(src, "pb\n", 3) == 0)
		p(stack_a, stack_b);
	else if (ft_strncmp(src, "pa\n", 3) == 0)
		p(stack_b, stack_a);
	else if (ft_strncmp(src, "ra\n", 3) == 0)
		r(stack_a);
	else if (ft_strncmp(src, "rb\n", 3) == 0)
		r(stack_b);
	else if (ft_strncmp(src, "rra\n", 4) == 0)
		rr(stack_a);
	else if (ft_strncmp(src, "rrb\n", 4) == 0)
		rr(stack_b);
	else if (ft_strncmp(src, "sa\n", 3) == 0)
		s(stack_a);
	else if (ft_strncmp(src, "sb\n", 3) == 0)
		s(stack_b);
	else if (ft_strncmp(src, "ss\n", 3) == 0)
		ss(stack_b, stack_a);
	else if (ft_strncmp(src, "rr\n", 3) == 0)
		r_r(stack_b, stack_a);
	else if (ft_strncmp(src, "rrr\n", 3) == 0)
		rrr(stack_b, stack_a);
	else
		ft_putstr_fd("Error\n", 2);
}

void	ok_or_ko(t_data *data_s, t_list **stack_a)
{
	if (check_stack_a(*stack_a) == 1 && \
	ft_lstsize(*stack_a) == data_s->node_num - 1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}
