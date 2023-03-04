/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:52:58 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 21:30:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX && sign > 0)
			return (-1);
		if (nb > INT_MAX && sign < 0)
			return (0);
		i++;
	}
	return (nb * sign);
}

unsigned long	right_time(struct timeval time)
{
	unsigned long			res;

	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

void	printf_msg(char *str, t_philo *philo, int f)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	printf("%lu ms philo %d %s\n", right_time(now) \
	- right_time(philo->data->start_time), philo->nb, str);
	pthread_mutex_lock(&philo->data->print);
	if (f != 1)
		pthread_mutex_unlock(&philo->data->print);
}
