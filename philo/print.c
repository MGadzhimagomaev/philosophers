/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:04:09 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 21:15:59 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->write_lock);
	printf("%ld %d %s\n", get_timestamp()
		- philo->data->init_time, philo->num, msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}
