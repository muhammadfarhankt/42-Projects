/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:24:11 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:24:12 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	pa_bonus(t_node **a, t_node **b, int print)
{
	t_node	*first_a;
	t_node	*first_b;

	if (*b == NULL)
		return ;
	first_a = *a;
	first_b = *b;
	*b = first_b->next;
	first_b->next = first_a;
	*a = first_b;
	if (print)
		write(1, "pa\n", 3);
}

void	pb_bonus(t_node **b, t_node **a, int print)
{
	t_node	*first;
	t_node	*first_b;

	if (*a == NULL)
		return ;
	first = *a;
	first_b = *b;
	*a = first->next;
	first->next = first_b;
	*b = first;
	if (print)
		write(1, "pb\n", 3);
}
