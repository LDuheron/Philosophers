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

// IS_ALIVE : This function ensures that the philosopher is alive
// by checking if the time elapsed since it's last meal is inferior
// to the time_to_die parameter. Returns 1 if the philosopher is alive.
// Returns 0 if the philosopher died and update it's status.

int	is_alive(t_philo *philo)
{
	if (philo->hour_death < philo->data_p.time_to_die + get_time())
		return (1);
	philo->status = DEAD;
	printf("%ld %i died\n", get_time(), philo->id);
	philo->data_p.nb_death += 1;
	return (0);
}

// IS_FED : This function checks if the philosopher has eaten the
// amount of time required (define in the parameters of the program).

void	is_fed(t_philo *philo)
{
	if (philo->nb_meal == philo->data_p.nb_required_meal)
		philo->status = FED;
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->data_p.mutex);
	printf("%ld %i has taken a fork\n", get_time(), philo->id);
	philo->status = EATING;
	printf("%ld %i is eating\n", get_time(), philo->id);
	usleep(philo->data_p.time_to_eat);
	philo->nb_meal += 1;
	philo->hour_death = get_time() + philo->data_p.time_to_die;
	pthread_mutex_unlock(philo->data_p.mutex);
}

void	is_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	printf("%ld %i is sleeping\n", get_time(), philo->id);
	usleep(philo->data_p.time_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	philo->status = THINKING;
	printf("%ld %i is thinking\n", get_time(), philo->id);
}
