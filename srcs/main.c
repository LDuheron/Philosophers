/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/20 20:00:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Chaque philosophe doit etre represente par un thread.
// Un philosophe = une fourchette. Pas plus de 200 philosophers.
// Seulement un mutex par thread.

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 6)
	{
		initialize_data_structure(&data, argv);
		create_a_mutex(&data);
		create_a_philosopher(&data);
		philo(&data);
		// clean_philo(&data);
	}
	else
		printf("Error : please enter five arguments.");
	return (0);
}
