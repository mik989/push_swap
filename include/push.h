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

#ifndef PUSH_H
# define PUSH_H

# include "../libft/libft.h"

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct node
{
	int			val;
	int			len;
	struct node	*next;
}t_node;

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

t_node	*find_long_chain(int len, t_node *n, t_node *p);
t_node	*fill_chain(int len, int *v);
int		find_min_pos(t_list *a);
int		is_min(t_list *a);
void	push_min(t_list **a, t_list **b);
void	ft_free_mat(char **str);
int		ft_best_mov(int size, int *mov_a, int *mov_b);
int		ft_best_mov2(int mov_a, int mov_b);
int		ft_is_min_pos(t_list **a);
int		ft_is_max_pos(t_list **a);
int		min_pos(t_list *tmp, int i);
void	ft_move_min_max(int mov_a, int mov_b, t_list **a, t_list **b);
void	ft_move_max_min(int mov_a, int mov_b, t_list **a, t_list **b);
void	ft_move_max(int mov_a, int mov_b, t_list **a, t_list **b);
void	ft_move_min(int mov_a, int mov_b, t_list **a, t_list **b);
int		ft_index(int size, int *mov_a, int *mov_b);
int		ft_abs_a(int mov_a, int mov_b);
int		ft_abs_b(int mov_a, int mov_b);
int		ft_min(int mov_a, int mov_b);
int		ft_max(int mov_a, int mov_b);
char	**ft_strcheck(char **av);
void	ft_init_flag(t_list *op);
void	free_list(t_list *head);
int		ft_max_len(int *dp, int len);
int		ft_lstsize(t_list *lst);
int		ft_sorting(int ac, t_list **a, t_list **b);
void	ft_buildstacka(int ac, char **av, t_list **a, t_list **new);
void	ft_checkdouble(int ac, char **av, int free);
void	ft_checkisnumber(char *av, char **str, int free);
void	nextgreaterelement(t_list **a, t_list *op, int n);
void	ft_ultimate_movement(t_list **a);
int		ft_is_max_pos(t_list **a);
int		ft_is_min_arr(int *arr, int size);
int		ft_is_min_arr_pos(int *arr, int size);
void	ft_printlist(t_list *o);
void	ft_movement(t_list **a, t_list **b, int k);
void	ft_sort_lis(t_list **a, t_list **b, int size);
void	ft_free_stack(t_list *start);
void	ft_butta_su(t_list **a, int i);
void	ft_butta_giu(t_list **a, int i);
int		min_pos(t_list *tmp, int i);
int		ft_is_min_pos(t_list **a);
void	ft_push_min_a(t_list **a, t_list **b);
void	ft_lstdsp(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_list_size(t_list *lst);
int		ft_is_ordered(t_list *a);
void	ft_sort(t_list **a, t_list **b, int size);
int		*ft_lis_algo(int *array, int size);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ft_rotlst(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	swap(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ft_revlst(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif