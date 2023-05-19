/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:18:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 19:31:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(int code)
{
	if (code == 0)
		printf("An error occured in pthread_mutex_init.\n");
	if (code == 1)
		printf("An error occured in pthread_create.\n");
	if (code == 2)
		printf("An error occured in pthread_join.\n");
	// clean
	exit(1);
}
