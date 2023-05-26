/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/22 17:14:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Pas encore utilisee la fonction pthread detach ni memset

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		initialize_data_structure(&data, argc, argv);
		create_a_mutex(&data);
		create_a_philosopher(&data);
		philo(&data);
		clean_philo(&data);
	}
	else
		printf("Error : wrong number of arguments.");
	return (0);
}
