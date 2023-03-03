/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:15:34 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 15:59:03 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->p_nb)
	{		
		if (i + 1 == data->p_nb)
		{
			data->philo[i].lf = &data->forks[0];
			data->philo[i].rf = &data->forks[i];
			return ;
		}
		data->philo[i].lf = &data->forks[i + 1];
		data->philo[i].rf = &data->forks[i];
		i++;
	}
}

void	initialize_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		data->philo[i].nb = i + 1;
		data->philo[i].data = data;
		data->philo[i].m_nb = 0;
		data->philo[i].death = 0;
		i++;
	}
}

t_data	*initialize_general(int ac, char **av)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		return (NULL);
	data->p_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_m = ft_atoi(av[5]);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meals, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->time, NULL);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->p_nb);
	data->philo = malloc (sizeof(t_philo) * data->p_nb);
	initialize_forks(data);
	initialize_philo(data);
	return (data);
}

void	initialize_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		pthread_create(&data->philo[i].t, NULL, \
		globale_action, &data->philo[i]);
		// gettimeofday(&data->d1, NULL);
		i++;
	}

}
