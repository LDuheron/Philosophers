/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:28:19 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/26 11:28:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
// int max + int min

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		if (nbr > INT_MAX / 10)
			return (OVERFLOW);
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * sign;
	return (nbr);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}
