/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:26:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 14:06:13 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork_action(t_philo *philo)
{
	pthread_mutex_lock(philo->rf);
	printf_msg("took right fork", philo);
	pthread_mutex_lock(philo->lf);
	printf_msg("took left fork", philo);
}

void	eating_action(t_philo *philo)
{
	// usleep(philo->data->t_eat * 1000);
	pthread_mutex_lock(&philo->data->meals);
	philo->m_nb++;
	if (philo->m_nb == philo->data->nb_m)
			philo->data->check1++;
	// printf_msg("is eating", philo);
	pthread_mutex_unlock(&philo->data->meals);
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
}

void	sleeping_action(t_philo *philo)
{
	usleep(philo->data->t_sleep * 1000);
	printf_msg("is sleeping", philo);
}
