/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:37:37 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/06 22:33:12 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>

/* Errors*/

# define ERROR_NUM_OF_ARGS "Error: wrong number of arguments."
# define ERROR_DIG "Error: invalid input (only positive integers allowed)."

/* Structs*/

typedef struct s_params
{
	int	cnt_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	cnt_times_to_eat;
}	t_params;

typedef struct s_philo
{
	int				num;
	long			last_meal_ts;
	int				meals_cnt;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_params		params;
	long			init_time;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	stop_lock;
	t_philo			*philos;
}	t_data;

/* Function prototypes */
int		parse(int argc, char **argv);
void	assign_params(t_params *params, char **argv, int argc);
int		init_data(t_data *data);
void	cleanup(t_data *data);

#endif
