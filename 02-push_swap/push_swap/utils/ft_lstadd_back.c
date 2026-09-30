/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:18:18 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:18:19 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_node **stack, t_node *new)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
}
