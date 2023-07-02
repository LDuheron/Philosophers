/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:11:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/07/02 14:57:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p->mutex_dead);
	if (philo->data_p->stop == 1)
	{
		pthread_mutex_unlock(&philo->data_p->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data_p->mutex_dead);
	return (0);
}

// GET TIME : This function returs the current time stamp in microseconds
// using the gettimeoftheday() fuction which returns time in seconds and 
// miliseconds.

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			milisecondes;
	size_t			secondes;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		error(ERROR_TIME);
	milisecondes = (size_t)tv.tv_usec / 1000;
	secondes = (size_t)tv.tv_sec * 1000;
	time = secondes + milisecondes;
	return (time);
}

// FT_USLEEP : Recreating the usleep function because the latter 
// is imprecise.

void	ft_usleep(size_t time, t_philo *philo)
{
	size_t	start;

	start = get_time();
	(void) philo;
	while ((get_time() < start + time))
		usleep(100);
}

void	print_in_routine(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data_p->mutex_print);
	if (check_stop(philo) == 0)
	{
		if (status == FORK)
			printf("%lu %i has taken a fork\n",
				get_time() - philo->start_time, philo->id + 1);
		if (status == EATING)
			printf("%lu %i is eating\n",
				get_time() - philo->start_time, philo->id + 1);
		if (status == SLEEPING)
			printf("%lu %i is sleeping\n",
				get_time() - philo->start_time, philo->id + 1);
		if (status == THINKING)
			printf("%lu %i is thinking\n",
				get_time() - philo->start_time, philo->id + 1);
	}
	pthread_mutex_unlock(&philo->data_p->mutex_print);
}
