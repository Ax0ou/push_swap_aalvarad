/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:54 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/16 17:27:25 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_clear(t_node **stack)
{
	t_node *current;
	t_node *tmp;

	if (!stack)
		return;
	while (*stack)
	{
		current = *stack;
		tmp = current->next;
		free(current);
		*stack = tmp;
	}
}
