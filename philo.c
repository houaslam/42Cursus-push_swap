/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:15 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/03 21:23:09 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
