/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:20:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/07/02 15:05:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// IS_DEAD : This function ensures that the philosopher is alive
// by checking if the time elapsed since it's last meal is inferior
// to the time_to_die parameter. Returns 1 if the philosopher is alive.
// Returns 0 if the philosopher died and update it's status.

int	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_dead);
	data->stop = 1;
	pthread_mutex_unlock(&data->mutex_dead);
	pthread_mutex_lock(&data->mutex_print);
	printf("%lu %i died\n"COLOR_RESET, get_time() - data->philos[i].start_time,
		data->philos[i].id + 1);
	pthread_mutex_unlock(&data->mutex_print);
	return (1);
}

// IS_FED : This function checks if the philosopher has eaten the
// amount of time required (define in the parameters of the program)
// and changes the status of the philosopher if so.

int	is_fed(t_philo *philo)
{
	if (philo->data_p->nb_required_meal == NO_MEAL_REQUIREMENT)
		return (0);
	pthread_mutex_lock(&philo->data_p->mutex_meal);
	if (philo->nb_meal == philo->data_p->nb_required_meal)
	{
		pthread_mutex_unlock(&philo->data_p->mutex_meal);
		pthread_mutex_lock(&philo->data_p->mutex_dead);
		philo->data_p->stop = 1;
		pthread_mutex_unlock(&philo->data_p->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data_p->mutex_meal);
	return (0);
}

int	all_philo_fed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (is_fed(&data->philos[i]) == 0)
			return (0);
		i++;
	}
	pthread_mutex_lock(&data->mutex_dead);
	data->stop = 1;
	pthread_mutex_unlock(&data->mutex_dead);
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data			*data;
	int				i;

	data = (t_data *) arg;
	i = 0;
	while (check_stop(&data->philos[0]) == 0)
	{
		i = 0;
		while (i < data->nb_philo && check_stop(&data->philos[0]) == 0)
		{
			pthread_mutex_lock(&data->mutex_monitor);
			if (data->philos[i].hour_death < get_time())
				is_dead(data, i);
			else
				all_philo_fed(data);
			pthread_mutex_unlock(&data->mutex_monitor);
			i++;
		}
		usleep(900);
	}
	return (NULL);
}
