/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:51:47 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 22:12:44 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	create_threads(t_data *data)
{
	int	i;

	data->init_time = get_timestamp();
	i = 0;
	while (i < data->params.cnt_of_philos)
	{
		data->philos[i].last_meal_ts = data->init_time;
		i++;
	}
	i = 0;
	while (i < data->params.cnt_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, 
				routine, &data->philos[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->params.cnt_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
