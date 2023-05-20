/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:49:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/20 18:27:07 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

int	mail;

void	*routine()
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread[200];
	int			i;

	mail = 0;
	i = 0;
	(void) argv;
	while (i < argc)
	{
		pthread_create(&thread[i], NULL, &routine, NULL);
		printf("Thread %i started\n", i);
		i++;
	}
	printf("Thread %i is done\n", i);
	i = 0;
	while (i < argc)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return (1);
}
