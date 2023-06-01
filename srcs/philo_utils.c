/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:11:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/01 17:16:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// GET TIME : This function returs the current time stamp in microseconds
// using the gettimeoftheday() fuction which returns time in seconds and 
// miliseconds. Second = microsecond * 1000. Milisecond = microsecond / 1000.
int	get_time(void)
{
	struct timeval	tv;
	int				milisecondes;
	int				secondes;
	int				time;

	gettimeofday(&tv, NULL);
	milisecondes = tv.tv_usec * 1000;
	secondes = tv.tv_sec / 1000;
	time = secondes + milisecondes;
	return (time);
}

// FT_USLEEP : Recreating the usleep function because the latter is imprecise.
// void	ft_usleep(int time)
// {
// 	while (time)
// 	{
// 		usleep(1);
// 		is_alive();
// 	}
// }