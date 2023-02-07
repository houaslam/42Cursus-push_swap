/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/06 19:29:00 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_data	data;

	// data.tab = malloc(sizeof(int) * (ac - 1));
	if (ac > 2)
	{
		data.node_num = ac - 1;
		stack_a = NULL;
		fill_stack(&stack_a, av);
		// node_num(data);
		handl_arg(av);
		check_stack_a(stack_a);
		struct_to_tab(stack_a, &data);
		// sort(data.tab, ac - 1);
		if (data.node_num <= 5)
			small_swap(data, &stack_a);
		aff(stack_a);
		printf("/////\n");
		// else
		// {
		// 	node_num(data);
		// 	push_swap(stack_a, data);
		// }
	}
	else
		write(1, "Error\n", 6);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 9223372036854775807 && sign > 0)
			return (-1);
		if (nb > 9223372036854775807 && sign < 0)
			return (0);
		i++;
	}
	return (nb * sign);
}

t_list	*conv(char **av, t_list *stack_a)
{
	int	i;

	i = 1;
	while (av[i])
	{
		stack_a = malloc(sizeof(t_list));
		stack_a->x = ft_atoi(av[i]);
		stack_a = stack_a->next;
		i++;
	}
	stack_a = malloc(sizeof(t_list));
	stack_a->next = NULL;
	return (stack_a);
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
	exit(0);
}
