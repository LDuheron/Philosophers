/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/21 20:17:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->hour_death = get_time() + philo->data_p.time_to_die;
	while (is_alive(philo) == 1 && philo->status != FED)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		is_fed(philo);
	}
	return (NULL);
}

void	philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&(data)->philosophers[i].thread, NULL,
			&routine, &(data->philosophers[i]));
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join((data)->philosophers[i].thread, NULL);
		i++;
	}
}
