/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:45:25 by nel-mous          #+#    #+#             */
/*   Updated: 2023/05/03 14:43:38 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_param *params, pthread_t *thread, pthread_mutex_t *forks,
				char **av)
{
	if (init_mutexes(params, forks, thread) != 1)
		return (0);
	if (init_params(params, thread, forks, av) != 1)
		return (0);
	if (create_philo(params, thread, forks) != 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_param			*params;
	pthread_t		*thread;
	pthread_mutex_t	*forks;

	if (ac == 6 || ac == 5)
	{
		if (check_args(av) == 1 || ft_atoi(av[1]) == 0)
			return (1);
		params = malloc(sizeof(t_param) * ft_atoi(av[1]));
		if (!params)
			return (0);
		params->n_philo = ft_atoi(av[1]);
		thread = malloc(sizeof(pthread_t) * params->n_philo);
		if (!thread)
			return (free(params), 0);
		forks = malloc(sizeof(pthread_mutex_t) * params->n_philo);
		if (!forks)
			return (free(params), free(thread), 0);
		if (init(params, thread, forks, av) != 1)
			return (0);
		free_all(params, forks, thread, params->n_philo);
	}
	else
		write(2, "ERROR\n", 6);
	return (0);
}
