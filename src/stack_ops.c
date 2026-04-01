/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:54 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/01 10:36:38 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		current = *stack;
		tmp = current->next;
		free(current);
		*stack = tmp;
	}
}

void	build_stack(t_node **stack, int *numbers, int size)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (!stack || !numbers || !size)
		return ;
	while (i < size)
	{
		tmp = create_node(numbers[i]);
		if (!tmp)
		{
			stack_clear(stack);
			error_exit();
		}
		stack_add_back(stack, tmp);
		i++;
	}
}
