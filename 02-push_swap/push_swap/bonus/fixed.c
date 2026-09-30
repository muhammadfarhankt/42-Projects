/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:22:05 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:22:07 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(t_node **a, t_node **b, t_ops **instructions)
{
	ft_lstclear_bonus(a);
	ft_lstclear_ops_bonus(instructions);
	ft_lstclear_bonus(b);
}

void	verify_and_exec(t_node **a, t_node **b, t_ops **instructions)
{
	int		size;
	t_ops	*current;

	size = ft_lstsize_ops_bonus(*instructions);
	current = *instructions;
	while (size)
	{
		if (!verify_bonus((*instructions)->content))
			return ;
		current = current->next;
		size--;
	}
	size = ft_lstsize_ops_bonus(*instructions);
	current = *instructions;
	while (size)
	{
		execute(current->content, a, b);
		size--;
		current = current->next;
	}
}
