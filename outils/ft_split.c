/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:18:44 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/15 14:09:46 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dim1(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
	i++;
	}
	return (j + 1);
}

char	**ft_freestr(char **arr, int p)
{
	while (p >= 0)
	{
		free(arr[p]);
		p--;
	}
	free(arr);
	return (NULL);
}

char	**ft_func(char **arr, char *s, char c)
{
	int	i;
	int	p;
	int	k;

	i = 0;
	p = 0;
	k = 0;
	while (p < ft_dim1(s, c) && s[i])
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		i = k;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[p] = ft_substr(s, k, i - k);
		k = i;
		if (!arr[p])
			return (ft_freestr(arr, p - 1));
		p++;
	}
	arr[p] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		j;
	size_t	i;
	size_t	size ;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	size = ft_dim1((char *)s, c);
	p = malloc((size + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (!ft_func(p, (char *)s, c))
		return (NULL);
	return (p);
}
