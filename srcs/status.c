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
	pthread_mutex_lock(philo->left_fork);
	print_in_routine(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_in_routine(philo, FORK);
	print_in_routine(philo, EATING);
	philo->hour_death = get_time() + philo->data_p.time_to_die;
	usleep(philo->data_p.time_to_eat);
	philo->nb_meal += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p.mutex_print);
	printf("%d %i is sleeping\n", philo->start_time - get_time(), philo->id + 1);
	ft_usleep(philo->data_p.time_to_sleep);
	pthread_mutex_unlock(&philo->data_p.mutex_print);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_p.mutex_print);
	printf("%d %i is thinking\n", philo->start_time - get_time(), philo->id + 1);
	pthread_mutex_unlock(&philo->data_p.mutex_print);
}
