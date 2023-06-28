/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:52:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/27 16:45:48 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_a_mutex(t_data *data)
{
	pthread_mutex_t	*mutex_tmp;
	int				i;

	i = 0;
	mutex_tmp = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&mutex_tmp[i], NULL) != 0)
			error(ERROR_MUTEX_INIT);
		i++;
	}
	data->mutex = mutex_tmp;
}

void	create_a_philosopher(t_data *data)
{
	t_philo	*philos_tmp;
	int		i;

	i = -1;
	philos_tmp = malloc(sizeof(t_philo) * (data->nb_philo));
	while (++i < data->nb_philo)
	{
		philos_tmp[i].data_p = data;
		philos_tmp[i].id = i;
		philos_tmp[i].status = THINKING;
		philos_tmp[i].nb_meal = 0;
		philos_tmp[i].start_time = get_time();
		philos_tmp[i].hour_death = data->time_to_die + get_time();
		if (i % 2 == 0)
		{
			philos_tmp[i].first_fork = &data->mutex[i % data->nb_philo];
			philos_tmp[i].second_fork = &data->mutex[(i + 1) % data->nb_philo];
		}
		else
		{
			philos_tmp[i].first_fork = &data->mutex[(i + 1) % data->nb_philo];
			philos_tmp[i].second_fork = &data->mutex[i % data->nb_philo];
		}
	}
	data->philos = philos_tmp;
}

void	initialize_data_structure(t_data *data, int argc, char **argv)
{
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		error(ERROR_MUTEX_INIT);
	if (pthread_mutex_init(&data->mutex_monitor, NULL) != 0)
		error(ERROR_MUTEX_INIT);
	data->mutex = NULL;
	data->philos = NULL;
	data->nb_death = 0;
	data->nb_philo = get_arg(argv[1]);
	check_nb_philo(data->nb_philo);
	data->fork = get_arg(argv[1]);
	data->time_to_die = get_arg(argv[2]);
	data->time_to_eat = get_arg(argv[3]);
	data->time_to_sleep = get_arg(argv[4]);
	data->nb_required_meal = NO_MEAL_REQUIREMENT;
	if (argc == 6)
		data->nb_required_meal = get_arg(argv[5]);
}
