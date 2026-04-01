/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:36:38 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/01 10:36:38 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_silent(t_node **stack_a)
{
	t_node	*last;
	t_node	*prev;

	if (!(*stack_a) || stack_size(*stack_a) < 2)
		return ;
	last = *stack_a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rra(t_node **stack_a)
{
	rra_silent(stack_a);
	write(1, "rra\n", 4);
}

void	rrb_silent(t_node **stack_b)
{
	t_node	*last;
	t_node	*prev;

	if (!(*stack_b) || stack_size(*stack_b) < 2)
		return ;
	last = *stack_b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrb(t_node **stack_b)
{
	rrb_silent(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	write(1, "rrr\n", 4);
}
