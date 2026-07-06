/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:17 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/06 20:59:23 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_params	params;
	int			parse_check;

	if (argc != 5 && argc != 6)
		return (printf("%s\n", ERROR_NUM_OF_ARGS), 1);
	if ((parse_check = parse(argc, argv)) == -1)
		return (1);
	else
		assign_params(&params, argv, argc);
	if (params.cnt_of_philos < 1)
		return (printf("%s\n", ERROR_DIG), 1);
	printf("%d\n", params.cnt_of_philos);
	printf("%d\n", params.time_to_die);
	printf("%d\n", params.time_to_eat);
	printf("%d\n", params.time_to_sleep);
	printf("%d\n", params.cnt_times_to_eat);
}
