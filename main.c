/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:45:25 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 18:41:28 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_param *params, pthread_t *thread, pthread_mutex_t *forks,
				char **av)
{
	init_mutex(params, forks);
	init_params(params, av);
	if (params->death_time == 0 || params->eat_time == 0
		|| params->sleep_time == 0 || params->nb_t_must_eat == 0)
		return ;
	create_philo(params, thread);
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
		if(!params)
			return(1);
		params->n_philo = ft_atoi(av[1]);
		thread = malloc(sizeof(pthread_t) * params->n_philo);
		if(!thread)
			return(1);
		forks = malloc(sizeof(pthread_mutex_t) * params->n_philo);
		if(!forks)
			return(1);
		// if (!params || !forks || !thread)
		// 	return (free(params), free(forks), free(thread), 1);
		init(params, thread, forks, av);
		free_all(params, forks, thread);
	}
	else
		write(2, "ERROR\n", 6);
	return (0);
}
