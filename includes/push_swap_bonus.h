/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/22 14:37:33 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_BONUS_H
# define  PUSH_SWAP_BONUS_H

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
}					t_list;

typedef struct t_data
{
	int		node_num;
	int		*tab;
	int		size_a;
	int		ind;
}		t_data;
// libft
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(char *src, char *src2, int nb);

// tools
void	s(t_list **stack_a);
void	p(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a);
void	r(t_list **stack_a);
void	r_r(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	write_r(t_list **stack, char *str);
void	write_s(t_list **stack, char *str);
void	write_rr(t_list **stack, char *str);
void	write_p(t_list **stack_2, t_list **stack, char *str);

//general 
void	get_val(t_list **stack_a, t_data *data);
void	get_val_end(t_list	**stack_a, t_data *data);
void	handl_arg(char **av, t_data *data);
void	fill_stack(t_list **stack_a, t_data *data);
void	check_int(char **str);
void	check_double(t_data *data);
int		check_stack_a(t_list *stack_a);
void	compare_exec(char *src, t_list	**stack_a, t_list **stack_b);
void	ok_or_ko(t_data *data, t_list **stack_a);
void	check(char *s);

//split
int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_freestr(char **arr, int p);

//gnl
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char	*s2);
char	*ft_check(char *buf, int fd);
char	*ft_handle(char *buf);
char	*after(char *buf);

#endif