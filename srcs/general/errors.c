/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:30 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/21 14:12:55 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_int(char **str)
{
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+' || str[j][i] == ' ')
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
	while (j < data->size_a)
	{
		i = 0;
		while (i < data->size_a)
		{
			if (data->tab[i] == data->tab[j] && i != j)
			{
				write(2, "/Error\n", 7);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	count_num(char **str, t_data *data)
{
	data->size_a = 0;
	while (str[data->size_a])
		data->size_a++;
}

void	copy_to_tab(t_data *data, char **str)
{
	int	o;

	o = 0;
	while (str[o])
	{
		data->tab[o] = ft_atoi(str[o]);
		free(str[o++]);
	}
	free(str);
}

void	handl_arg(char **av, t_data *data)
{
	int		i;
	char	**str;
	int		o;
	char	*ptr;

	i = 1;
	o = 0;
	ptr = NULL;
	while (av[i])
	{
		ptr = ft_strjoin(ptr, av[i++]);
		ptr = ft_strjoin(ptr, " ");
	}
	str = ft_split(ptr, ' ');
	free(ptr);
	if (str[0] == NULL)
		ft_putstr_fd("Error\n", 2);
	check_int(str);
	count_num(str, data);
	data->tab = malloc(sizeof(int) * data->size_a);
	copy_to_tab(data, str);
	check_double(data);
}
