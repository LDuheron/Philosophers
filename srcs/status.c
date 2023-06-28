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
	// printf("_________ : %i\n\n\n\n", philo->data_p->time_to_die);
	// printf("_______get time__ : %zu\n\n\n\n", get_time());
	philo->hour_death = get_time() + philo->data_p->time_to_die;
	ft_usleep(philo->data_p->time_to_eat, philo);
	
	philo->nb_meal += 1;
	pthread_mutex_unlock(&philo->data_p->mutex_monitor);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p->mutex_print);
	printf("%lu %i is sleeping\n", get_time() - philo->start_time,
		philo->id + 1);
	ft_usleep(philo->data_p->time_to_sleep, philo);
	pthread_mutex_unlock(&philo->data_p->mutex_print);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p->mutex_print);
	printf("%lu %i is thinking\n", get_time() - philo->start_time,
		philo->id + 1);
	usleep(100);
	pthread_mutex_unlock(&philo->data_p->mutex_print);
}
