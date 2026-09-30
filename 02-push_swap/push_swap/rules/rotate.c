/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:20:51 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:20:52 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a, int print)
{
	t_node	*first;
	t_node	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	set_position(*a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int print)
{
	t_node	*b1;
	t_node	*b2;

	if (ft_lstsize(*b) < 2)
		return ;
	b1 = *b;
	b2 = *b;
	while (b2->next)
		b2 = b2->next;
	*b = b1->next;
	b1->next = NULL;
	b2->next = b1;
	set_position(*b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	set_position(*a);
	set_position(*b);
	if (print)
		write(1, "rr\n", 3);
}
