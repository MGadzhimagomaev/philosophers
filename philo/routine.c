/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:34:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 22:55:56 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_ts = get_timestamp();
	philo->meals_cnt++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->params.time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->params.cnt_of_philos == 1)
	{
		print_status(philo, "has taken a fork");
		return (ft_usleep(philo->data->params.time_to_die), NULL);
	}
	if (philo->num % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		take_forks(philo);
		if (stopped(philo->data))
		{
			pthread_mutex_unlock (philo->l_fork);
			pthread_mutex_unlock (philo->r_fork);
			break ;
		}
		eat(philo);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->params.time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
