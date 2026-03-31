/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:17:30 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/31 16:37:54 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    indexer(t_node *stack_a)
{
    t_node  *current_i;  // pointeur qui parcourt chaque node (le "casier actuel")
    t_node  *current_j;  // pointeur qui compare avec tous les autres (le "regard")
    int     count;       // compteur de valeurs plus petites

    if (!stack_a)        // garde : si la liste est vide, rien à faire
        return ;

    current_i = stack_a; // on démarre au 1er node
    while (current_i)    // on parcourt chaque node jusqu'à NULL
    {
        count = 0;             // on repart à 0 pour chaque node
        current_j = stack_a;  // on repart du début pour comparer

        while (current_j)     // on parcourt toute la liste
        {
            // si un node a une valeur plus petite → on compte
            if (current_j->value < current_i->value)
                count++;
            current_j = current_j->next; // on avance le "regard"
        }

        // le nombre de valeurs plus petites = le rang = l'index
        current_i->value = count;
        current_i = current_i->next; // on passe au node suivant
    }
}

int     get_max_bits(int size)
{
	int	bit;

	bit = 0;
	while (size > 0)
	{
		size >>= 1;
		bit++;
	}
	return (bit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int bit;
	int i;

	bit = 0;
	while (bit < get_max_bits(size))
	{
		i = stack_size(*stack_a);
		while (i > 0)
		{
			if (((*stack_a)->value >> bit) & 1)
    			ra(stack_a);
			else
    			pb(stack_b, stack_a);
			i--;
		}
		bit++;
		while (stack_size(*stack_b) > 0)
    		pa(stack_a, stack_b);
	}
}

void    sort_stack(t_node **stack_a, t_node **stack_b, int len)
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

void    bring_min_to_top(t_node **stack_a)
{
    int pos;
    int size;

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
