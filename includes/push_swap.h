/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/15 14:51:33 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4
# endif

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
	int	*tab;
	int	size_a;
	int	size_b;
	int	i;
	int	factor;
	int	n;
	int	start;
	int	end;
	int	offset;
	int	middle;
}		t_data;
// libft
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

// tools
void	s(t_list **stack_a);
void	p(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a);
void	r(t_list **stack_a);
void	write_r(t_list **stack, char *str);
void	write_s(t_list **stack, char *str);
void	write_rr(t_list **stack, char *str);
void	write_p(t_list **stack_2, t_list **stack, char *str);

// small
void	check_do(t_list **stack_a);
void	check_do_2(t_list **stack_a, int mid, int max, int min);
void	check_close_s(t_list **stack_a, t_data *data, t_list **stack_b, int nb);
void	small_swap(t_data data, t_list **stack_a);
void	get_val(t_list **stack_a, t_data *data);
void	get_val_end(t_list	**stack_a, t_data *data);
void	only_four(t_list **stack_a, t_data *data, int nb);
void	only_five(t_list **stack_a, t_data *data);
void	get_out_up(t_list **stack_a, t_list **stack_b, int nb);
void	get_out_down(t_list **stack_a, t_list **stack_b, int nb);
int		mid_index(t_list *stack_a, int max, int min);
int		min_index(t_list *stack_a);
int		max_index(t_list *stack_a);

//general 
void	aff(t_list *node);
void	handl_arg(char **av, t_data *data);
void	fill_stack(t_list **stack_a, t_data data);
void	check_int(char **str);
void	check_double(t_data *data);
int		check_stack_a(t_list *stack_a);
void	main_push(int ac, char **av);
void	check_cases(t_list *stack_a, t_data data);

//!small
void	get_back(t_list **stack);
void	figure_para(t_data *data, int size);
int		check_index(t_list **stack_a, int end, int start);
void	push_swap(t_data *data, t_list **stack_a, t_list **stack_b);
void	push_back(t_data *data, t_list **stack_b, t_list **stack_a);
void	check_max(t_list **stack_b, t_data *data, t_list **stack_a);
void	get_out_up_(t_list **stack_a, t_list **stack_b, t_data *data);
void	check_close(t_list **stack_a, t_data *data, t_list **stack_b);
void	get_out_up_b(t_list **stack_b, t_list **stack_a, t_data *data);
void	get_out_down_(t_list **stack_a, t_list **stack_b, t_data *data);
void	get_out_down_b(t_list **stack_b, t_list **stack_a, t_data *data);

//split
int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_freestr(char **arr, int p);

void	aff1(int *tab, int ac);

//gnl
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char	*s2);
char	*ft_check(char *buf, int fd);
char	*ft_handle(char *buf);
char	*after(char *buf);

#endif