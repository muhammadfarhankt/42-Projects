/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:23:18 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:23:18 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_lstadd_back_bonus(t_node **stack, t_node *new)
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
	last = ft_lstlast_bonus(*stack);
	last->next = new;
}

void	ft_lstadd_back_ops_bonus(t_ops **stack, t_ops *new)
{
	t_ops	*tmp;
	t_ops	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast_ops_bonus(*stack);
	last->next = new;
}
