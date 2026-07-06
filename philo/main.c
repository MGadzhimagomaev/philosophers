/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:17 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/06 22:32:52 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (printf("%s\n", ERROR_NUM_OF_ARGS), 1);
	if (parse(argc, argv) == -1)
		return (1);
	assign_params(&data.params, argv, argc);
	if (init_data(&data) == -1)
		return (1);
	int i = 0;
	while (i < data.params.cnt_of_philos)
	{
		printf("philo %d: l_fork=%p r_fork=%p\n",
			data.philos[i].num,
			(void *)data.philos[i].l_fork,
			(void *)data.philos[i].r_fork);
		i++;
	}
	pthread_mutex_lock(&data.forks[0]);
	printf("lock ok\n");
	pthread_mutex_unlock(&data.forks[0]);
	cleanup(&data);
	printf("%d\n", data.params.cnt_of_philos);
	printf("%d\n", data.params.time_to_die);
	printf("%d\n", data.params.time_to_eat);
	printf("%d\n", data.params.time_to_sleep);
	printf("%d\n", data.params.cnt_times_to_eat);
}
