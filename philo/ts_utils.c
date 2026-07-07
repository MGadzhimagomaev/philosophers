/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:50:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 21:16:11 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}

void	ft_usleep(long ms)
{
	long	start_time;

	start_time = get_timestamp();
	while (get_timestamp() - start_time < ms)
		usleep(100);
}
