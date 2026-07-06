/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/07/06 20:47:27 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static	int	ft_atoi(const char *nptr)
{
	int						i;
	int						sign;
	unsigned long long int	output;

	i = 0;
	sign = 1;
	output = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		output = output * 10 + (nptr[i] - '0');
		i++;
		if (output > INT_MAX)
			return (-1);
	}
	return (sign * output);
}

static	int	check_only_numbers(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (0);
}

int	parse(int argc, char **argv)
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		if (check_only_numbers(argv[i]) == -1)
			return (printf("%s\n", ERROR_DIG), -1);
		num = ft_atoi(argv[i]);
		if (num < 0)
			return (printf("%s\n", ERROR_DIG), -1);
		i++;
	}
	return (1);
}

void	assign_params(t_params *params, char **argv, int argc)
{
	params->cnt_of_philos = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == 5)
		params->cnt_times_to_eat = ft_atoi(argv[5]);
	else
		params->cnt_times_to_eat = -1;
}
