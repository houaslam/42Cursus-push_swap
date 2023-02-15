/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/15 17:02:42 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	*ptr;
	char	*hold;
	t_list	*stack_a;
	t_data	data;

	if (ac >= 2)
	{
		stack_a = NULL;
		handl_arg(av, &data);
		fill_stack(&stack_a, data);
		free(data.tab);
		get_val_end(&stack_a, &data);
		ptr = malloc(sizeof(char *));
		ptr = NULL;
		while (1)
		{
			hold = get_next_line(0);
			if (!hold)
				break ;
			ptr = ft_strjoin(ptr, hold);
			free(hold);
		}
	}
	else
		ft_putstr_fd("error\n", 2);
}	

