/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:11:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/25 14:20:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// GET TIME : This function returs the current time stamp in microseconds
// using the gettimeoftheday() fuction which returns time in seconds and 
// miliseconds. Second = microsecond * 1000. Milisecond = microsecond / 1000.

int	get_time(void)
{
	struct timeval	tv;
	int				milisecondes;
	int				secondes;
	int				time;

	if (gettimeofday(&tv, NULL) == -1)
		error(ERROR_TIME);
	milisecondes = (size_t)tv.tv_usec / 1000;
	secondes = (size_t)tv.tv_sec * 1000;
	time = secondes + milisecondes;
	return (time);
}

// FT_USLEEP : Recreating the usleep function because the latter 
// is imprecise. Allows us to implement a synchronization mecanism.

void	ft_usleep(useconds_t time)
{
	unsigned int	start;

	start = get_time();
	while (time > (get_time() - start))
		usleep(time);
}

void	print_in_routine(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data_p.mutex_print);
	if (status == FORK)
		printf("%d %i has taken a fork\n", philo->start_time - get_time(), philo->id + 1);
	if (status == EATING)
		printf("%d %i is eating\n", philo->start_time - get_time(), philo->id + 1);
	if (status == DEAD)
		printf("%d %i died\n", philo->start_time - get_time(), philo->id + 1);
	if (status == SLEEPING)
		printf("%d %i is sleeping\n", philo->start_time - get_time(), philo->id + 1);
	if (status == THINKING)
		printf("%d %i is thinking\n", philo->start_time - get_time(), philo->id + 1);
	pthread_mutex_unlock(&philo->data_p.mutex_print);
}
