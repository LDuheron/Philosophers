/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:20:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/28 10:41:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// IS_DEAD : This function ensures that the philosopher is alive
// by checking if the time elapsed since it's last meal is inferior
// to the time_to_die parameter. Returns 1 if the philosopher is alive.
// Returns 0 if the philosopher died and update it's status.

void	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_print);
	data->nb_death += 1;
	i = 0;
	printf(RED"%lu %i died\n"COLOR_RESET, get_time() - data->philos[i].start_time,
		data->philos[i].id + 1);
	while (i < data->nb_philo)
	{
		data->philos[i].status = DEAD;
		i++;
	}
	pthread_mutex_unlock(&data->mutex_print);
}

// IS_FED : This function checks if the philosopher has eaten the
// amount of time required (define in the parameters of the program)
// and changes the status of the philosopher if so.

int	is_fed(t_philo *philo)
{
	if (philo->data_p->nb_required_meal == NO_MEAL_REQUIREMENT)
		return (0);
	pthread_mutex_lock(&philo->data_p->mutex_monitor);
	if (philo->nb_meal == philo->data_p->nb_required_meal)
	{
		philo->status = FED;
		pthread_mutex_unlock(&philo->data_p->mutex_monitor);
		return (1);
	}
	pthread_mutex_unlock(&philo->data_p->mutex_monitor);
	return (0);
}

int	all_philo_fed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		is_fed(&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].status != FED)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data			*data;
	size_t			current_time;
	int				i;

	data = (t_data *) arg;
	while (data->nb_death == 0)
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			pthread_mutex_lock(&data->mutex_monitor);
			current_time = get_time();
			if (get_time() >= data->philos[i].hour_death)
			{
				is_dead(data, i);
				pthread_mutex_unlock(&data->mutex_monitor);
				return (NULL);
			}
			pthread_mutex_unlock(&data->mutex_monitor);
			if (is_dead_check(data) == 1 || all_philo_fed(data) == 1)
				return (NULL);
		}
		usleep(900);
	}
	return (NULL);
}
