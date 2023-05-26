/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:40 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/26 15:46:18 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

//////////////////////////////////////////////////////////////////
//																//
//								ENUM							//
//																//
//////////////////////////////////////////////////////////////////

enum e_type_status_philo
{
	ALIVE,
	EATING,
	SLEEPING,
	THINKING,
	FED,
	FORK,
	DEAD
} ;

//////////////////////////////////////////////////////////////////
//																//
//							STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_data
{	
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_print;
	struct s_philo	*philosophers;
	int				nb_death;
	int				fork;
	int				nb_philo;
	int				nb_required_meal;
	int				current_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_data;

typedef struct s_philo
{
	t_data			data_p;
	int				id;
	int				nb_meal;
	int				status;
	pthread_t		thread;
	int				hour_death;
}	t_philo;

//////////////////////////////////////////////////////////////////
//																//
//																//
//							PROTOTYPES 							//
//																//
//																//
//////////////////////////////////////////////////////////////////

// Main.c
int			main(int argc, char **argv);

// Exit.c
void		clean_philo(t_data *data);
void		error(int code);

// Initialization.c
void		create_a_mutex(t_data *data);
void		create_a_philosopher(t_data *data);
void		initialize_data_structure(t_data *data, int argc, char **argv);

// Philo.c
void		philo(t_data *data);

// Philo_utils.c
int			get_time(void);

// Status.c
int			is_alive(t_philo *philo);
void		is_fed(t_philo *philo);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
void		print_in_routine(t_philo *philo, int status);

//////////////////////////////////////////////////////////////////
//																//
//                   	IN CHECK INPUT DIR                      //
//																//
//////////////////////////////////////////////////////////////////

// Input_is_valid.c
void		check_nb_philo(int nb_philo);
int			get_arg(char *input);
int			is_valid(char *input);

// Input_is_valid_utils.c
int			ft_atoi(const char *str);
int			is_digit(int c);
int			is_sign(char c);

#endif