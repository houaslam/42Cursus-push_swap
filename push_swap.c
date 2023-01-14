/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/14 19:51:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac > 1)
	{
		stack_a = NULL;
		handl_arg(&stack_a, av);
		aff(stack_a);
	}
	else
		write(1, "Error\n", 6);
}

void	aff(t_list *stack_a)
{
	while (stack_a)
	{
		printf("--->%d\n", stack_a->x);
		stack_a = stack_a->next;
	}
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
