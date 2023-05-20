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

int	is_alive(t_philo *philo, t_data *data)
{
	if ((philo->hour_death - data->current_time) < data->time_to_die)
		return (1);
	philo->status = DEAD;
	data->nb_death += 1;
	// printf("%i %i x died\n", data->current_time, philo->id);
	return (0);
}

// IS_FED : This function checks if the philosopher has eaten the
// amount of time required (define in the parameters of the program).

void	is_fed(t_philo *philo, t_data *data)
{
	if (philo->nb_meal == data->nb_required_meal)
		philo->status = FED;
}

void	is_eating(t_philo *philo, t_data *data)
{
	pthread_mutex_lock((&philo)->mutex));
	// printf("%i %i x has taken a fork\n", data->current_time, philo->id);
	philo->status = EATING;
	// printf("%i %i x is eating\n", data->current_time, philo->id);
	usleep(data->time_to_eat);
	philo->nb_meal += 1;
	pthread_mutex_unlock((&philo)->mutex));
	philo->status = THINKING;
}

void	is_sleeping(t_philo *philo, t_data *data)
{
	philo->status = SLEEPING;
	// printf("%i %i x is sleeping\n",data->current_time, philo->id);
	printf("Philo is sleeping\n");
	usleep(data->time_to_sleep);
	philo->status = THINKING;
}

void	is_thinking(t_philo *philo, t_data *data)
{
	(void) data;
	philo->status = THINKING;
	// printf("%i %i x is thinking\n", data->current_time, philo->id);
	printf("Philo is thinking\n");
}
