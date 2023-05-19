/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:52:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 19:35:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_data_structure(t_data *data, char **argv)
{
	data->nb_death = 0;
	data->nb_philo = get_arg(argv[1]);
	check_nb_philo(data->nb_philo);
	data->fork = get_arg(argv[1]);
	data->time_to_die = get_arg(argv[2]);
	data->time_to_eat = get_arg(argv[3]);
	data->time_to_sleep = get_arg(argv[4]);
	data->nb_required_meal = get_arg(argv[5]);
}

// changer prototype pour init l'id a N.

void	initialize_philo_structure(t_philo *philo, int i)
{
	if (pthread_mutex_init((&philo)->mutex, NULL) != 0)
		error(0);
	philo->id = i;
	philo->status = START;
	philo->nb_meal = 0;
	philo->last_meal = 0;
}
