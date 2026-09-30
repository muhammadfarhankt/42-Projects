/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:22:33 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:22:34 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	not_sorted_bonus(t_node **stack)
{
	t_node	*current;

	current = (*stack);
	while (current)
	{
		if (current->next != NULL)
		{
			if (current->value > current->next->value)
				return (1);
		}
		current = current->next;
	}
	return (0);
}
