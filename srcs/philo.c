/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:27:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 14:48:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

init mutex
{
	
}

void	*routine()
{
	printf("TEST THREADS\n");
	while (is_alive(philo) == 1 && philo->status != FED)
	{
		
	}
}

void	philo(t_data *data)
{
	pthread_t	t1;
	p_thread_mutex_t	mutex;

	(void)		data;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		error();
	if (pthread_mutex_init(&mutex, NULL) != 0)
		error();
	if (pthread_join(t1, NULL) != 0)
		error();
}
