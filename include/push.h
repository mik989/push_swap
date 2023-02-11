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

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}t_list;

void 	sa(t_list **a);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_revlst(t_list **lst);
void	ft_rra(t_list **a);
void	ft_rra(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
void	ft_rotlst(t_list **lst);
void	ft_ra(t_list **a);
void	swap(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ft_rr(t_list **a, t_list **b);


#endif
