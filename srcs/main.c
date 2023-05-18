/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 23:29:06 by lduheron         ###   ########.fr       */
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

	if (argc == 6)
	{
		initialize_data_structure(&data, argv);
		philo(&data);
	}
	return (0);
}
