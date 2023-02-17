/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/17 14:52:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	main(int ac, char **av)
{
	char	*ptr;
	char	**res;
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
		free(data.tab);
		get_val_end(&stack_a, &data);
		ptr = malloc(sizeof(char *));
		while (1)
		{
			hold = get_next_line(0);
			if (!hold)
				break ;
			ptr = ft_strjoin(ptr, hold);
			free(hold);
		}
		res = ft_split(ptr, '\n');
		// while (*res)
		// {
		// 	printf("=======>%s", *res);
		// 	res++;
		// }
		free(ptr);
		compare_exec(res, stack_a, stack_b);
		if (check_stack_a(stack_a) == 1)
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	else
		ft_putstr_fd("error\n", 2);
}	

void	compare_exec(char **src, t_list	*stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (src[i])
	{
		printf("-->%s", src[i]);
		if (strncmp(src[i], "pa\n", 2) == 1)
			p(&stack_a, &stack_b);
		else if (strncmp(src[i], "pb\n", 2) == 1)
			p(&stack_b, &stack_a);
		else if (strncmp(src[i], "pa\n", 2) == 1)
			p(&stack_a, &stack_b);
		else if (strncmp(src[i], "ra\n", 2) == 1)
			r(&stack_a);
		else if (strncmp(src[i], "rb\n", 2) == 1)
			r(&stack_b);
		else if (strncmp(src[i], "rra\n", 3) == 1)
			rr(&stack_a);
		else if (strncmp(src[i], "rrb\n", 3) == 1)
			rr(&stack_b);
		else if (strncmp(src[i], "sa\n", 2) == 1)
			s(&stack_a);
		else if (strncmp(src[i], "sb\n", 2) == 1)
			s(&stack_b);
		i++;
	}
}
