/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:20:47 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/09 17:17:57 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int	has_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	validate_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number_str(tokens[i])
			|| !fits_in_int(tokens[i]))
		{
			free_tokens(tokens);
			error_exit();
		}
		i++;
	}
}

int	*parse_numbers(int argc, char **argv)
{
	char	**tokens;
	int		*numbers;
	int		len;

	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (NULL);
	validate_tokens(tokens);
	len = tokens_len(tokens);
	numbers = tokens_to_numbers(tokens, len);
	if (has_duplicates(numbers, len))
	{
		free(numbers);
		free_tokens(tokens);
		error_exit();
	}
	free_tokens(tokens);
	return (numbers);
}

int	*tokens_to_numbers(char **tokens, int len)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * len);
	if (!numbers)
	{
		free_tokens(tokens);
		error_exit();
	}
	i = 0;
	while (tokens[i])
	{
		numbers[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (numbers);
}
