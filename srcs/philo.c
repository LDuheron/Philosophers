/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/20 21:07:05 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine_test2()
// {
// 	while (data->nb_death == 0 && philo->status != FED)
// 	{
// 		printf("New philosopher created :)\n");
// 	}
// 	return (NULL);
// }

// 	// if (pthread_join(philo->thread, NULL) != 0)
// 	// 	error(2);
// }

// void	*real_routine()
// {
// 	while (data->nb_death == 0 && philo->status != FED)
// 	{
// 		is_eating();
// 		is_sleeping();
// 		is_thinking();
// 	}
// }

void	*routine_test1()
{
	printf("in routine\n");
	return (NULL);
}

void	philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&(data)->philosophers[i], NULL, &routine_test1, NULL);
		printf("Thread %i started\n", i);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(&data->philosophers[i], NULL);
		i++;
	}
}
