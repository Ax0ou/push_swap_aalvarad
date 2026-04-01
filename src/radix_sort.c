/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:17:30 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/01 10:23:01 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_node *stack_a)
{
	t_node	*current;
	t_node	*other;

	current = stack_a;
	while (current)
	{
		current->index = 0;
		other = stack_a;
		while (other)
		{
			if (other->value < current->value)
				current->index++;
			other = other->next;
		}
		current = current->next;
	}
}

int	get_max_bits(int size)
{
	int	bit;

	bit = 0;
	size--;
	while (size > 0)
	{
		size >>= 1;
		bit++;
	}
	return (bit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	bit;
	int	max_bits;
	int	i;

	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			i++;
		}
		while (stack_size(*stack_b) > 0)
			pa(stack_a, stack_b);
		bit++;
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
	{
		indexer(*stack_a);
		radix_sort(stack_a, stack_b, len);
	}
}

void	bring_min_to_top(t_node **stack_a)
{
	int	pos;
	int	size;

	size = stack_size(*stack_a);
	pos = find_min_pos(*stack_a);
	while (pos != 0)
	{
		if (pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		pos = find_min_pos(*stack_a);
	}
}
