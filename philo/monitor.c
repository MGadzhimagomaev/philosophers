/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:32:02 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 22:45:35 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static int	philo_died(t_data *data, int i)
{
	long	last_meal;

	pthread_mutex_lock(&data->meal_lock);
	last_meal = data->philos[i].last_meal_ts;
	pthread_mutex_unlock(&data->meal_lock);
	if (get_timestamp() - last_meal > data->params.time_to_die)
	{
		set_stop(data);
		pthread_mutex_lock(&data->write_lock);
		printf("%ld %d died\n", get_timestamp() - data->init_time,
			data->philos[i].num);
		pthread_mutex_unlock(&data->write_lock);
		return (1);
	}
	return (0);
}

static int	saturation_check(t_data *data)
{
	int	i;
	int	done;

	if (data->params.cnt_times_to_eat == -1)
		return (0);
	done = 1;
	i = 0;
	while (i < data->params.cnt_of_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].meals_cnt < data->params.cnt_times_to_eat)
			done = 0;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (done)
		set_stop(data);
	return (done);
}

void	monitor(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->params.cnt_of_philos)
		{
			if (philo_died(data, i))
				return ;
			i++;
		}
		if (saturation_check(data))
			return ;
		usleep(1000);
	}
}
