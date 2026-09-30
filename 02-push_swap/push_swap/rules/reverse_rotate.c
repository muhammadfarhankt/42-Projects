/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:20:43 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:20:44 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **a, int print)
{
	t_node	*first;
	t_node	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	first = *a;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	*a = tmp->next;
	tmp->next = NULL;
	set_position(*a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	t_node	*first;
	t_node	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	first = *b;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	*b = tmp->next;
	tmp->next = NULL;
	set_position(*b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	set_position(*a);
	set_position(*b);
	if (print)
		write(1, "rrr\n", 4);
}
