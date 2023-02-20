/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:30 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/20 14:07:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_int(char **str)
{
	int		i;
	int		j;

	j = 1;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+' || str[i][j] == ' ')
			i++;
		while (str[j][i])
		{
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == ' '))
			{
				write(2, "Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	check_double(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->node_num)
	{
		i = 0;
		while (i < data->node_num)
		{
			if (data->tab[i] == data->tab[j] && i != j)
			{
				write(2, "Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	handl_arg(char **av, t_data *data)
{
	int		i;
	char	**str;
	int		o;

	i = 1;
	o = 0;
	data->node_num = 0;
	data->tab = malloc(sizeof(int) * 3);
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (str[0] == NULL)
			ft_putstr_fd("Error\n", 2);
		check_int(str);
		o = 0;
		while (str[o])
		{
			data->tab[data->node_num] = ft_atoi(str[o]);
			free(str[o++]);
			data->node_num++;
		}
		free(str);
		i++;
	}
	check_double(data);
}
