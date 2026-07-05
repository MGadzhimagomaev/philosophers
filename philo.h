#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

/* Errors*/

# define ERROR_NUM_OF_ARGS "Error: wrong number of arguments."
# define ERROR_DIG "Error: invalid input (only integers allowed)."

/* Structs*/

typedef	struct	s_params
{
	int	cnt_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	cnt_times_to_eat;
}	t_params;

/* Function prototypes */
int		main(int argc, char **argv);
int		parse(int argc, char **argv);
void	assign_params(t_params *params, char **argv, int argc);

#endif
