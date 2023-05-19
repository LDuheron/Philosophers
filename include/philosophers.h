/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:40 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 19:36:45 by lduheron         ###   ########.fr       */
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
	START,
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
	int			fork;
	int			nb_philo;
	int			nb_required_meal;
	int			nb_death;
	suseconds_t	current_time;
	suseconds_t	time_to_die;
	suseconds_t	time_to_eat;
	suseconds_t	time_to_sleep;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				id;
	int				status;
	int				nb_meal;	
	suseconds_t		last_meal;
}	t_philo;

//////////////////////////////////////////////////////////////////
//																//
//																//
//							PROTOTYPES 							//
//																//
//																//
//////////////////////////////////////////////////////////////////

// Main.c
int		main(int argc, char **argv);

// Erroc.c
void	error(int code);

// Philo.c
t_philo	create_a_philosopher(int i);
void	philo(t_data *data);

// Philo_utils.c
int		get_time(void);

// Status.c
int		is_alive(t_philo *philo, t_data *data);
void	is_fed(t_philo *philo, t_data *data);
void	is_eating(t_philo *philo, t_data *data);
void	is_sleeping(t_philo *philo, t_data *data);
void	is_thinking(t_philo *philo, t_data *data);

//////////////////////////////////////////////////////////////////
//																//
//                      IN STRUCTURES DIR                       //
//																//
//////////////////////////////////////////////////////////////////

// Input_is_valid.c
void	check_nb_philo(int nb_philo);
int		is_valid(char *input);
int		get_arg(char *input);

// Input_is_valid_utils.c
int		ft_atoi(const char *str);
int		is_digit(int c);
int		is_sign(char c);

// Structure_management.c
void	initialize_data_structure(t_data *data, char **argv);
void	initialize_philo_structure(t_philo *philo, int i);

#endif