/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:30 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/04 15:24:19 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_int(char **str)
{
	int		i;
	int		j;

	j = 1;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
			{
				write(1, "+Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	check_double(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 1;
		while (av[i])
		{
			if (strcmp(av[j], av[i]) == 0 && i != j)
			{
				write(1, "/Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	handl_arg(char **av)
{
	check_int(av);
	check_double(av);
}
