/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:18:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/07/02 15:04:48 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	return (0);
}

void	clean_philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->mutex_fork)
	{
		while (i < data->nb_philo)
		{
			pthread_mutex_destroy(&data->mutex_fork[i]);
			i++;
		}
		free(data->mutex_fork);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_meal);
	pthread_mutex_destroy(&data->mutex_monitor);
	pthread_mutex_destroy(&data->mutex_print);
}

void	error(int code)
{
	if (code == ERROR_MUTEX_INIT)
		ft_putstr_fd("An error occured in pthread_mutex_init.\n", 2);
	if (code == ERROR_T_CREATE)
		ft_putstr_fd("An error occured in pthread_create.\n", 2);
	if (code == ERROR_T_JOIN)
		ft_putstr_fd("An error occured in pthread_join.\n", 2);
	if (code == 3)
	{
		ft_putstr_fd("Error : please enter a number of philosophers ", 2);
		ft_putstr_fd("included in array [1;200].\n", 2);
	}
	if (code == ERROR_NEGATIVE_INPUT)
	{
		ft_putstr_fd("Error : please enter only strictly", 2);
		ft_putstr_fd(" positive digit as parameters.\n", 2);
	}
	if (code == OVERFLOW)
		ft_putstr_fd("Error : overflow.\n", 2);
}
