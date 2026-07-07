/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:57:44 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 21:31:55 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	destroy_forks(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

static int	init_mutexes(t_data *data)
{
	int	i;
	int	n;

	n = data->params.cnt_of_philos;
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (destroy_forks(data, i), -1);
		i++;
	}
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (destroy_forks(data, i), -1);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (pthread_mutex_destroy(&data->write_lock),
			destroy_forks(data, i), -1);
	if (pthread_mutex_init(&data->stop_lock, NULL) != 0)
		return (pthread_mutex_destroy(&data->meal_lock),
			pthread_mutex_destroy(&data->write_lock),
			destroy_forks(data, i), -1);
	return (0);
}

static void	init_philos(t_data *data)
{
	int	i;
	int	n;

	n = data->params.cnt_of_philos;
	i = 0;
	while (i < n)
	{
		data->philos[i].num = i + 1;
		data->philos[i].last_meal_ts = 0;
		data->philos[i].meals_cnt = 0;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % n];
		data->philos[i].data = data;
		i++;
	}
}

int	init_data(t_data *data)
{
	data->stop = 0;
	data->init_time = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->params.cnt_of_philos);
	if (!data->forks)
		return (-1);
	data->philos = malloc(sizeof(t_philo) * data->params.cnt_of_philos);
	if (!data->philos)
		return (free(data->forks), -1);
	if (init_mutexes(data) == -1)
		return (free(data->forks), free(data->philos), -1);
	init_philos(data);
	return (0);
}
