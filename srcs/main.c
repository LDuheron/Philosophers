/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/07/02 17:34:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;

	if (!(argc == 5 || argc == 6))
		return (error(ARG));
	if (initialize_data_structure(&data, argc, argv) == SUCCESS)
	{
		if (data.nb_philo == 1)
			philo_one(&data);
		else
		{
			if (pthread_create(&monitor, NULL, &monit_routine, &data) != 0)
				error(ERROR_MUTEX_INIT);
			else
			{
				philo(&data);
				pthread_join(monitor, NULL);
			}
		}
		clean_philo(&data);
	}
	return (0);
}
