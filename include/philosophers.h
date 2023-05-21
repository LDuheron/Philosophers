/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:40 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/21 20:14:46 by lduheron         ###   ########.fr       */
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
	EATING,
	SLEEPING,
	THINKING,
	FED,
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
	struct s_philo	*philosophers;
	int				nb_death;
	int				fork;
	int				nb_philo;
	int				nb_required_meal;
	suseconds_t		current_time;
	suseconds_t		time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
}	t_data;

typedef struct s_philo
{
	t_data			data_p;
	int				id;
	int				nb_meal;
	int				status;
	pthread_t		thread;
	suseconds_t		hour_death;
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
void		initialize_data_structure(t_data *data, char **argv);

// Philo.c
void		philo(t_data *data);

// Philo_utils.c
suseconds_t	get_time(void);

// Status.c
int			is_alive(t_philo *philo);
void		is_fed(t_philo *philo);
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