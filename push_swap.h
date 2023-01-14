/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/14 18:51:12 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				x;
	struct s_list	*next;
}					t_list;

// libft
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

// tools
void	s(t_list *stack_a);
void	p(t_list **stack_a, t_list *stack_b);

// del
void	aff(t_list *node);

// push_swap
t_list	*conv(char **av, t_list *stack_a);
void	check_int(char **av);
void	check_double(char **av);
t_list	*handl_arg(t_list **stack_a, char **av);

int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_freestr(char **arr, int p);

//
void sort(int *tab, int size);
void swap(int *a, int *b);
void	sort_main(int *a);

#endif