/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:23:41 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:23:42 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	dup_checker_bonus(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_lstclear_bonus(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = (NULL);
}

void	ft_lstclear_ops_bonus(t_ops **stack)
{
	t_ops	*current;
	t_ops	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current->content);
		free(current);
		current = tmp;
	}
	*stack = (NULL);
}

char	**free_the_split_v2_bonus(char **res)
{
	int	words;

	words = 0;
	if (!res)
		return (NULL);
	while (res[words])
	{
		free (res[words]);
		words++;
	}
	free(res);
	return (NULL);
}

void	handle_error_bonus(t_node **stack, char **res)
{
	ft_lstclear_bonus(stack);
	free_the_split_v2_bonus(res);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
