/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:30 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/10 21:03:44 by houaslam         ###   ########.fr       */
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

void	check_double(t_data data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data.node_num)
	{
		i = 0;
		while (i < data.node_num)
		{
			if (data.tab[i] == data.tab[j] && i != j)
			{
				write(1, "/Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	handl_arg(char **av, t_data data)
{
	int	i;
	int	j;
	char **str;
	int	o;

	i = 1;
	j = 0;
	o = 0;
	data.tab = malloc(sizeof(int) * (data.node_num));
	check_int(av);
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		while(str[o])
		{
			data.tab[j] = ft_atoi(str[o]);
			o++;
			j++;
		}
			i++;
	}
	check_double(data);
}
