/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/07 19:27:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <limits.h>

typedef struct s_list
{
	int				x;
	struct s_list	*next;
	int				index;
	int				num;
}					t_list;

typedef struct t_data
{
	int	node_num;
}		t_data;

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
void	s(t_list **stack_a);
void	p(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a);
void	r(t_list **stack_a);
void    write_r(t_list **stack, char *str);
void    write_s(t_list **stack, char *str);
void    write_rr(t_list **stack, char *str);
void    write_p(t_list **stack_2, t_list **stack, char *str);

// del
void	aff(t_list *node);

// push_swap
t_list	*conv(char **av, t_list *stack_a);
void	check_int(char **str);
void	check_double(char **av);
int		check_stack_a(t_list *stack_a);
void	handl_arg(char **av);
void	struct_to_tab(t_list *stack_a, t_data *data);
void	fill_stack(t_list **stack_a, char **av);
void	node_num(t_data data);
void	small_swap(t_data data, t_list **stack_a);
void	get_val(t_list **stack_a, t_data *data);
void    check_do(t_list **stack_a, t_data data);
void	get_val_end(t_list	**stack_a, t_data *data);
void	only_four(t_list	**stack_a, t_data *data);

//split
int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_freestr(char **arr, int p);

//
void	sort(int *tab, int size);
void	swap(int *a, int *b);
void	sort_main(int *a);
void	aff1(int *tab, int ac);

#endif