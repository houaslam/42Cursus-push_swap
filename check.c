/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:29:16 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 21:55:08 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_loop(t_data *data)
{
	int	i;
	struct timeval	now;

	i = 0;
	while (i < data->p_nb)
	{
		pthread_mutex_lock(&data->meals);
		if (data->check1 == data->p_nb)
			return ;
		pthread_mutex_unlock(&data->meals);
		pthread_mutex_lock(&data->death);
		gettimeofday(&now, NULL);

		if (right_time(now) - data->philo[i].store > (unsigned long)data->t_die)
		{
			printf_msg("is dead\n", &data->philo[i], 1);
			return ;
		}
		pthread_mutex_unlock(&data->death);
		if (i + 1 == data->p_nb)
			i = 0;
		i++;

	}
}

int	check_arg(char **str)
{
	int		i;
	int		j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '+' || str[j][i] == ' ')
				i++;
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == ' '))
			{
				printf("error\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_data(t_data *data, int ac)
{
	if (data->p_nb < 0 || data->t_die < 0)
		return (1);
	if (data->t_sleep < 0 || data->t_eat < 0)
		return (1);
	if (ac == 6 && data->nb_m < 0)
		return (1);
	return (0);
}
