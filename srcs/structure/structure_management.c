/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:52:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 10:25:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_data_structure(t_data *data, char **argv)
{
	data->nb_philo = get_arg(argv[1]);
	check_nb_philo(data->nb_philo);
	data->fork = get_arg(argv[1]);
	data->time_to_die = get_arg(argv[2]);
	data->time_to_eat = get_arg(argv[3]);
	data->time_to_sleep = get_arg(argv[4]);
	data->nb_time_eat = get_arg(argv[5]);
}

void	initialize_philo_structure(t_philo *philo)
{
	philo->status = START;
}

void	initialize_structures(t_data *data, t_philo *philo, char **argv)
{
	initialize_data_structure(data, argv);
	initialize_philo_structure(philo);
}
