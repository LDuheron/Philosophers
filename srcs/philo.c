/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/07/02 17:22:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	print_in_routine(philo, FORK);
	ft_usleep(philo->data_p->time_to_die, philo);
	printf("%lu %i died\n", get_time() - philo->data_p->philos[0].start_time, 1);
	return (NULL);
}

void	philo_one(t_data *data)
{
	pthread_create(&(data)->philos[0].thread, NULL,
		&routine_one, &(data->philos[0]));
	pthread_join((data)->philos[0].thread, NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (check_stop(philo) == 0)
	{
		if (check_stop(philo) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_eating(philo);
		if (check_stop(philo) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_sleeping(philo);
		if (check_stop(philo) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_thinking(philo);
	}
	return (NULL);
}

void	philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->mutex_monitor);
		data->philos[i].hour_death = data->time_to_die + get_time();
		pthread_mutex_unlock(&data->mutex_monitor);
		pthread_create(&(data)->philos[i].thread, NULL,
			&routine, &(data->philos[i]));
		i++;
	}
	i = -1;
	while (++i < data->nb_philo)
		pthread_join((data)->philos[i].thread, NULL);
}
