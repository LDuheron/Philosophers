/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 10:32:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Chaque philosophe doit etre represente par un thread.
// Un philosophe = une fourchette. Pas plus de 200 philosophers.
// Seulement un fork par philosphers.
// Seulement un mutex par fork.
// void	*test_thread()

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	if (argc == 6)
	{
		initialize_structures(&data, &philo, argv);
		// philo(&data);
	}
	else
		printf("Error : please enter five arguments.");
	return (0);
}
