/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:21:16 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:21:17 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **a, int print)
{
	t_node	*a1;
	t_node	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	a1 = *a;
	tmp = (*a)->next;
	a1->next = tmp->next;
	tmp->next = a1;
	*a = tmp;
	set_position(*a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int print)
{
	t_node	*b1;
	t_node	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	b1 = *b;
	tmp = (*b)->next;
	b1->next = tmp->next;
	tmp->next = b1;
	*b = tmp;
	set_position(*b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	set_position(*a);
	set_position(*b);
	if (print)
		write(1, "ss\n", 3);
}
