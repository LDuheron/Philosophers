/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:20:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/23 16:01:48 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// IS_DEAD : This function ensures that the philosopher is alive
// by checking if the time elapsed since it's last meal is inferior
// to the time_to_die parameter. Returns 1 if the philosopher is alive.
// Returns 0 if the philosopher died and update it's status.

void	is_dead(t_data *data, int i)
{
	data->nb_death += 1;
	pthread_mutex_lock(&data->mutex_print);
	printf("%d %i died\n", data->philosophers[i].start_time - get_time(), data->philosophers[i].id + 1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philosophers[i].status = DEAD;
		i++;
	}
	pthread_mutex_unlock(&data->mutex_print);
}

// IS_FED : This function checks if the philosopher has eaten the
// amount of time required (define in the parameters of the program)
// and changes the status of the philosopher if so.

void	is_fed(t_philo *philo)
{
	if (philo->nb_meal == philo->data_p.nb_required_meal)
		philo->status = FED;
}

int	all_philo_fed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		is_fed(&data->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philosophers[i].status != FED)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	long	current_time;
	int		i;

	data = (t_data *) arg;
	while (data->nb_death == 0)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			current_time = get_time();
			if (current_time > data->philosophers[i].hour_death)
			{
				is_dead(data, i);
				return (NULL);
			}
			i++;
		}
		if (all_philo_fed(data) || data->nb_death != 0)
			return (NULL);
	}
	return (NULL);
}
