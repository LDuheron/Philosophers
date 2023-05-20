/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/20 14:40:14 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine()
// {
// 	t_philo	philo;

// 	initialize_philo_structure(&philo);
// 	while (data->nb_death == 0 && philo->status != FED)
// 	{
// 		printf("New philosopher created :)\n");
// 	}
// 	pthread_mutex_destroy(&(philo)->mutex);
// 	return NULL;
// }

// void	create_a_philosopher(int i)
// {
// 	t_philo	philosopher;

// 	initialize_philo_structure(&philosopher, i);
// 	pthread_create
// 	return (philosopher);
// }

// void	philo(t_data *data, int nb_philo)
// {
// 	int			i;

// 	i = 0;
// 	while (i < data->nb_philo)
// 	{
// 		if (pthread_create(&thread[i], NULL, &create_a_philosopher(i), NULL) != 0)
// 			error(1);
// 		i++;
// 	}

// 	// if (pthread_join(philo->thread, NULL) != 0)
// 	// 	error(2);
// }

// tableau de pointeur vers structure philo?


void	clear_philo(t_data *data)
{
	int	i;

	i = 0;
	while (data->tab_philo[i])
	{
		pthread_mutex_destroy();
	}
}

t_philo	*create_a_philosopher(int i)
{
	t_philo	philosopher;

	initialize_philo_structure(&philosopher, i);

	return (philosopher);
}

void	philo(t_data *data)
{
	int	i;

	i = 0;
	data->tab_philo = malloc(sizeof(t_philo * data->nb_philo));
	while (i < data->philo)
	{
		tab_philo[i] = create_a_philosopher(i);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		run routine
		i++;
	}
	while (tab[i])
	{
		pthread_join(&thread, NULL);
		i++;
	}
}