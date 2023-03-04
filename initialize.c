/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:15:34 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 21:54:25 by houaslam         ###   ########.fr       */
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
		data->philo[i].store = 0;
		i++;
	}
}

t_data	*initialize_general(int ac, char **av)
{
	t_data	*data;

	if (check_arg(av) == 1)
		return (NULL);
	data = malloc (sizeof(t_data));
	if (!data)
		return (NULL);
	data->p_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_m = ft_atoi(av[5]);
	if (check_data(data, ac) == 1)
		return (NULL);
	initialize_mutex(data);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->p_nb);
	data->philo = malloc (sizeof(t_philo) * data->p_nb);
	if (!data->forks || !data->philo)
		return (NULL);
	initialize_forks(data);
	initialize_philo(data);
	return (data);
}

void	initialize_threads(t_data *data)
{
	struct timeval	now;
	int	i;

	i = 0;
	gettimeofday(&data->start_time, NULL);
	gettimeofday(&now, NULL);
	while (i < data->p_nb)
	{
		data->philo[i].store = right_time(now);
		pthread_create(&data->philo[i].t, NULL, \
		globale_action, &data->philo[i]);
		update_time(&data->philo[i]);
		usleep(100);
		i++;
	}

}

void	initialize_mutex(t_data *data)
{
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meals, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->time, NULL);

}
