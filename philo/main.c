/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:17 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/07 22:42:50 by mgadzhim         ###   ########.fr       */
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
	if (create_threads(&data) == -1)
		return (cleanup(&data), 1);
	cleanup(&data);
	return (0);
}
