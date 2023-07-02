/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:52:26 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 11:49:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_eating(t_philo *philo)
{	
	pthread_mutex_lock(philo->first_fork);
	print_in_routine(philo, FORK);
	pthread_mutex_lock(philo->second_fork);
	print_in_routine(philo, FORK);
	print_in_routine(philo, EATING);
	pthread_mutex_lock(&philo->data_p->mutex_monitor);
	philo->hour_death = get_time() + philo->data_p->time_to_die;
	pthread_mutex_unlock(&philo->data_p->mutex_monitor);
	ft_usleep(philo->data_p->time_to_eat, philo);
	pthread_mutex_lock(&philo->data_p->mutex_meal);
	philo->nb_meal += 1;
	pthread_mutex_unlock(&philo->data_p->mutex_meal);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p->mutex_print);
	printf("%lu %i is sleeping\n", get_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(&philo->data_p->mutex_print);
	ft_usleep(philo->data_p->time_to_sleep, philo);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p->mutex_print);
	printf("%lu %i is thinking\n", get_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(&philo->data_p->mutex_print);
	usleep(100);
}
