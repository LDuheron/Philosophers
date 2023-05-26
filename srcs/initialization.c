/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:52:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/26 15:37:01 by lduheron         ###   ########.fr       */
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
			error(0);
		i++;
	}
	data->mutex = mutex_tmp;
}

void	create_a_philosopher(t_data *data)
{
	t_philo	*philosophers_tmp;
	int		i;

	i = 0;
	philosophers_tmp = malloc(sizeof(t_philo) * (data->nb_philo));
	while (i < data->nb_philo)
	{
		philosophers_tmp[i].data_p = *data;
		philosophers_tmp[i].id = i + 1;
		philosophers_tmp[i].status = THINKING;
		philosophers_tmp[i].nb_meal = 0;
		philosophers_tmp[i].hour_death = data->time_to_die + get_time();
		i++;
	}
	data->philosophers = philosophers_tmp;
}

void	initialize_data_structure(t_data *data, int argc, char **argv)
{
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		error(0);
	data->mutex = NULL;
	data->philosophers = NULL;
	data->nb_death = 0;
	data->nb_philo = get_arg(argv[1]);
	check_nb_philo(data->nb_philo);
	data->fork = get_arg(argv[1]);
	data->time_to_die = get_arg(argv[2]);
	data->time_to_eat = get_arg(argv[3]);
	data->time_to_sleep = get_arg(argv[4]);
	data->nb_required_meal = 1;
	if (argc == 6)
		data->nb_required_meal = get_arg(argv[5]);
}
