/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:26:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 21:49:13 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork_action(t_philo *philo)
{
	pthread_mutex_lock(philo->rf);
	printf_msg("took right fork", philo, 0);
	pthread_mutex_lock(philo->lf);
	printf_msg("took left fork", philo, 0);
}

void	eating_action(t_philo *philo)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	philo->store = right_time(now);
	printf_msg("is eating", philo, 0);
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_lock(&philo->data->meals);
	philo->m_nb++;
	if (philo->m_nb == philo->data->nb_m)
			philo->data->check1++;
	pthread_mutex_unlock(&philo->data->meals);
	// update_time(philo);
}

void	sleeping_action(t_philo *philo)
{
	printf_msg("is sleeping", philo, 0);
	usleep(philo->data->t_sleep * 1000);
	printf_msg("is thinking", philo, 0);
	pthread_mutex_lock(&philo->data->death);
	pthread_mutex_unlock(&philo->data->death);
}

void	*globale_action(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		taking_fork_action(philo);
		eating_action(philo);
		sleeping_action(philo);
	}
	return (NULL);
}

void	update_time(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	// pthread_mutex_lock(&philo->data->death);
	philo->death = philo->store - philo->death;
	// pthread_mutex_unlock(&philo->data->death);
}
