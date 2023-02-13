/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/11 18:23:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	*ptr;
	char	*hold;

	main_push(ac, av);
	ptr = malloc(sizeof(char *));
	ptr = get_next_line(0);
	while (1)
	{
		hold = get_next_line(0);
		if (!hold)
			break ;
		ptr = ft_strjoin(ptr, hold);
		free(hold);
	}
}
