/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:25:50 by aalvarad          #+#    #+#             */
/*   Updated: 2026/03/18 14:07:27 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_silent(t_node **stack)
{
	int	tmp;

	if (stack_size(*stack) < 2)
		return;
	tmp = (*stack)->value;
	(*stack)->value = ((*stack)->next->value);
	(*stack)->next->value = tmp;
}

void	sa(t_node **stack)
{
	sa_silent(stack);
	write (1, "sa\n", 3);
}

void	sb_silent(t_node **stack)
{
	int	tmp;

	if (stack_size(*stack) < 2)
		return;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sb(t_node **stack)
{
	sb_silent(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sb_silent(stack_b);
	sa_silent(stack_a);
	write(1, "ss\n", 3);
}