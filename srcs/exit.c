/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:18:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/21 19:05:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
	free(data->philosophers);
}

void	error(int code)
{
	if (code == 0)
		printf("An error occured in pthread_mutex_init.\n");
	if (code == 1)
		printf("An error occured in pthread_create.\n");
	if (code == 2)
		printf("An error occured in pthread_join.\n");
	if (code == 3)
		printf("Error : please enter a number of philosophers included in array [2;200].\n");
	if (code == 4)
		printf("Error : please enter only strictly positive digits as parameters.\n");
	exit(1);
}
