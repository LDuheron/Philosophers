/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 19:30:15 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine()
// {
// 	t_philo	philo;

// 	initialize_philo_structure(&philo);
// 	while (data->nb_death == 0 && philo->status != FED)
// 	{
		// printf("New philosopher created :)\n");
// 	}
// 	pthread_mutex_destroy(&(philo)->mutex);
// }

t_philo	create_a_philosopher(int i)
{
	t_philo	philosopher;

	initialize_philo_structure(&philosopher, i);
	return (philosopher);
}

void	philo(t_data *data)
{
	int		i;
	char	**philo_tab;

	i = 0;
	philo_tab = NULL;
	while (i < data->nb_philo)
	{
		philo_tab[i] = create_a_philosopher(i);
		i++;
	}
	// if (pthread_create(&philo, NULL, &routine, NULL) != 0)
	// 	error(1);
	// if (pthread_join(&philo->thread, NULL) != 0)
	// 	error(2);
}
