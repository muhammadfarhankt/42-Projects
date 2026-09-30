/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:17:34 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:17:53 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_max(t_node *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}

t_node	*get_min(t_node *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value < tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}
