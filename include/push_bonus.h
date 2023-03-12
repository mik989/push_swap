/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:36:19 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 17:36:32 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_BONUS_H
# define PUSH_BONUS_H

# include "../libft/libft.h"

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_list
{
	int				content;
	int				i;
	int				j;
	int				val;
	int				flag;
	int				prev;
	int				c;
	struct s_list	*next;
}t_list;

char	**ft_strcheck(char **av);
int		ft_sorting(int ac, t_list **a, t_list **b);
void	ft_buildstacka(int ac, char **av, t_list **a, t_list **new);
void	ft_checkdouble(int ac, char **av);
void	ft_checkisnumber(char *av);
long	ft_long_atoi(const char *str);
void	check_long_int(char	*av);
int		is_int(char *str);
int		min_pos(t_list *tmp, int i);
int		ft_is_min_pos(t_list **a);
int		ft_is_max_pos(t_list **a);
int		is_min(t_list *a);
int		find_min_pos(t_list *a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	ft_revlst(t_list **lst);
void	rra(t_list **a);
void	rrr(t_list **a, t_list **b);
void	rrb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	swap(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ft_rotlst(t_list **lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdsp(t_list *lst);
char	*get_next_line(int fd);
void	free_stack(t_list *start);

#endif
