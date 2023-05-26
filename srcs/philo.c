/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/26 13:38:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine_one_philo(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *) arg;
// 	pthread_mutex_lock(&philo->data_p.mutex[philo->id]);
// 	printf("%d %i has taken a fork\n", get_time(), philo->id);
// 	philo->hour_death = get_time() + philo->data_p.time_to_die;
// 	while (is_alive(philo) == 1 && philo->status != FED)
// 	{
// 		is_eating(philo);
// 		is_sleeping(philo);
// 		is_thinking(philo);
// 		is_fed(philo);
// 	}
// 	return (NULL);
// }

// // ONE_PHILO : This function handles the case where there is 
// // only one philosopher. As a philosopher needs two forks to eat,
// // he takes the only one available, then wait for the second fork
// // which doesn't exist and die as the time_to_eat pass.
// void	one_philo(t_data *data)
// {
// 	if (pthread_mutex_init(&data->mutex[0], NULL) != 0)
// 		error(0);
// 	create_a_philosopher(data);
// 	pthread_create(&(data)->philosophers[0].thread, NULL, 
//		&routine_one_philo, &(data->philosophers[0]))
// 	// printf("%d %i died\n", get_time(), philo->id);
// 	clean(philo);
// }

// checker entre chaque action si alive
// %2 pour fourchette gauche droite
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
