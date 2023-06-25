/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:40 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/25 14:08:42 by lduheron         ###   ########.fr       */
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

# define SUCCESS 1
# define ERROR_MALLOC 2
# define ERROR_TIME 3

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
	int				current_time;
	int				fork;
	int				nb_philo;
	int				nb_required_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_data;

typedef struct s_philo
{
	t_data			data_p;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				start_time;
	int				id;
	int				nb_meal;
	int				status;
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

// Monitor.c
void		is_dead(t_data *data, int i);
void		is_fed(t_philo *philo);
int			all_philo_fed(t_data *data);
void		*monitor_routine(void *arg);

// Philo.c
void		philo(t_data *data);
void		*routine(void *arg);

// Philo_utils.c
void		ft_usleep(useconds_t time);
int			get_time(void);
void		print_in_routine(t_philo *philo, int status);

// Status.c
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);

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