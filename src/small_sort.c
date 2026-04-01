/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:18:31 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/01 10:36:38 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && a > c)
		ra(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	bring_min_to_top(stack_a);
	pb(stack_b, stack_a);
	bring_min_to_top(stack_a);
	pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	find_min_pos(t_node *stack_a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		i;

	if (!stack_a)
		return (-1);
	current = stack_a;
	min = stack_a->value;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	is_sorted(t_node *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
