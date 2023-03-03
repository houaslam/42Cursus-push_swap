/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:15 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 14:14:16 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&philo->data->now, NULL);
	printf("%lu ms philo %d %s\n", right_time(philo->data->now) \
	- right_time(philo->data->start_time), philo->nb, str);
	pthread_mutex_unlock(&philo->data->print);
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

void	check_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		pthread_mutex_lock(&data->meals);
		if (data->check1 == data->p_nb)
			return ;
		pthread_mutex_unlock(&data->meals);
		if (i + 1 == data->p_nb)
			i = 0;
		i++;

	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac == 5 || ac == 6)
		data = initialize_general(ac, av);
	else
		return (0);
	if (!data)
		return (0);
	gettimeofday(&data->start_time, NULL);
	initialize_threads(data);
	check_loop(data);
	i = 0;
	while (i < data->p_nb)
	{
		pthread_detach(data->philo[i].t);
		i++;
	}
	return (0);
}
