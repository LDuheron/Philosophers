/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:40 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/19 10:30:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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
	DONE,
	DEAD
} ;

//////////////////////////////////////////////////////////////////
//																//
//							STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_data
{
	int	nb_philo;
	int	fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_time_eat;
}	t_data;

typedef struct s_philo
{
	int	status;
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

// Philo.c
void	philo(t_data *data);

// Philo_utils.c

int		ft_strlen(char *str);

//////////////////////////////////////////////////////////////////
//																//
//					IN STRUCTURES DIR 	  						//
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
void	initialize_philo_structure(t_philo *philo);
void	initialize_structures(t_data *data, t_philo *philo, char **argv);

#endif