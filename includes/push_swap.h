/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:55:52 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/17 16:21:45 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../libft/libft.h"

typedef	struct s_node
{
	int value;
	struct s_node *next;
} t_node;


/* parsing / tokens */
t_node	*create_node(int value);
t_node 	*stack_last(t_node *stack);
char	**get_tokens(int argc, char **argv);
void	free_tokens(char **tokens);
void	error_exit(void);
int		is_valid_number_str(char *s);
int		fits_in_int(char *s);
int		tokens_len(char **tokens);
int		*parse_numbers(int argc, char **argv, int *out_len);
int		*tokens_to_numbers(char **tokens, int len);
int		has_duplicates(int *arr, int len);
void	stack_add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);
void	stack_add_front(t_node **stack, t_node *new);
void	stack_clear(t_node **stack);
void	build_stack(t_node **stack, int *numbers, int size);
#endif
