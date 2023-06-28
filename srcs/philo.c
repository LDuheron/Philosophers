/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/28 11:06:19 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	print_in_routine(philo, FORK);
	ft_usleep(philo->data_p->time_to_die, philo);
	return (NULL);
}

int	is_dead_check(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->mutex_print);
	if (data->nb_death > 0)
		i = 1;
	else
		i = 0;
	pthread_mutex_unlock(&data->mutex_print);
	return (i);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	long	current_time;

	current_time = get_time();
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		ft_usleep(10, philo);
	while (is_dead_check(philo->data_p) == 0)
	{
		if (is_dead_check(philo->data_p) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_eating(philo);
		if (is_dead_check(philo->data_p) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_sleeping(philo);
		if (is_dead_check(philo->data_p) == 1 || is_fed(philo) == 1)
			return (NULL);
		is_thinking(philo);
	}
	return (NULL);
}

void	philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_philo == 1)
	{
		pthread_create(&(data)->philos[i].thread, NULL,
			&routine_one, &(data->philos[i]));
		pthread_join((data)->philos[i].thread, NULL);
	}
	else
	{
		while (i < data->nb_philo)
		{
			// if (i % 2 == 0)
			// 	usleep(50);
			data->philos[i].hour_death = data->time_to_die + get_time();
			pthread_create(&(data)->philos[i].thread, NULL,
				&routine, &(data->philos[i]));
			i++;
		}
		i = -1;
		while (++i < data->nb_philo)
			pthread_join((data)->philos[i].thread, NULL);
	}
}
