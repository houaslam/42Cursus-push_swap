/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:23:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/19 20:19:20 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_index(t_list **stack_a, int end, int start)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	search_in_sb(t_list **stack_b, int nb)
{
	t_list	*tmp;
	int		i;

	if (!*stack_b)
		return (-1);
	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == nb)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
