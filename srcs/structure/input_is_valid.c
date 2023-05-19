/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:08:44 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 10:33:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_nb_philo(int nb_philo)
{
	if (nb_philo < 2 || nb_philo > 200)
	{
		printf("Error : please enter a number of philosophers included in array [2;200].\n");
		exit (0);
	}
}

// Is_valid : This function ensures the input respects the required
// conditions : - to be a digit.
// 				- to be positive.

int	is_valid(char *input)
{
	int	i;

	i = 0;
	if (is_sign(input[i]) && input[i + 1] != '\0')
		i++;
	while (input[i] && is_digit(input[i]) == 1)
		i++;
	if (is_digit(input[i]) == 0 && input[i] != '\0')
		return (0);
	return (1);
}

// Get_arg : This function checks the validity of the input then 
// converts it from char* to int. Returns an error if the input is not valid.

// Passer en atol?
int	get_arg(char *input)
{
	int	value;

	if (is_valid(input) == 1)
	{
		value = ft_atoi(input);
		if (value > 0)
			return (value);
	}
	printf("Error, please enter only strictly positive digits as parameters.");
	exit(0);
}
