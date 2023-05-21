/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:27:30 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/21 13:06:18 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

// struct    timeval  {
//   time_t        tv_sec ;   //used for seconds
//   suseconds_t       tv_usec ;   //used for microseconds
// }

// GET_TIME : This function 

suseconds_t	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return(tv.tv_usec);
}

int	main(void)
{
	get_time();
	get_time();
	get_time();
	get_time();
	get_time();
	get_time();
	return (0);
}
