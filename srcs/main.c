/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/25 17:55:13 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;

	if (argc == 5 || argc == 6)
	{
		initialize_data_structure(&data, argc, argv);
		create_a_mutex(&data);
		create_a_philosopher(&data);
		pthread_create(&monitor, NULL, &monitor_routine, &data);
		philo(&data);
		pthread_join(monitor, NULL);
		clean_philo(&data);
	}
	else
		printf("Error : wrong number of arguments.\n");
	return (0);
}
