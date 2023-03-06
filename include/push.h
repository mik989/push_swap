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

typedef struct node {
	int val, len;
	struct node *next;
}lis_list;

typedef struct s_list
{
	int			content;
    int         len;
	struct s_list	*next;
}t_list;

int     ft_is_max_pos(t_list **a);
void ft_escamotage(int mov_a, int i, t_list **a, t_list **b);
int 	nextGreaterElement(t_list **a, int n);
void    ft_ultimate_movement(t_list **a);
int     ft_is_max(t_list **a);
int     ft_is_min_arr(int *arr, int size);
int     ft_is_min_arr_pos(int *arr, int size);
void ft_printlist(t_list *o);
int	ft_lstlisize(lis_list *lst);
void ft_movement(t_list **a, t_list **b, int k);
void    ft_sort_lis(t_list **a, t_list **b, int size);
void    ft_free_stack(t_list *start);
void    ft_butta_su(t_list **a, int i);
void    ft_butta_giu(t_list **a, int i);
int     min_pos(t_list *tmp, int i);
int     ft_is_min_pos(t_list **a);
void    ft_push_min_a(t_list **a, t_list **b);
void    ft_lstdsp(t_list *lst);
t_list	*ft_lstnew(int content);
int     ft_list_size(t_list *lst);
int     ft_is_ordered(t_list *a);
void	ft_sort(t_list **a, t_list **b, int size);
int     *ft_lis_algo(int *array, int size);
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
