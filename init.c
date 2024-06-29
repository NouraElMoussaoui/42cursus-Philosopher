/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:50:54 by nel-mous          #+#    #+#             */
/*   Updated: 2023/05/03 14:48:28 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_param *params, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < params->n_philo)
	{
		params[i].right_fork = &forks[i];
		params[i].left_fork = &forks[(i + 1) % params->n_philo];
		i++;
	}
}

int	init_mutexes(t_param *params, pthread_mutex_t *forks, pthread_t *thread)
{
	int	i;

	i = 0;
	params->m_print = malloc(sizeof(pthread_mutex_t));
	if (!params->m_print)
		return (free(params), free(forks), free(thread), 0);
	params->m_check = malloc(sizeof(pthread_mutex_t));
	if (!params->m_check)
		return (free(params), free(forks), free(thread),
			free(params->m_print), 0);
	if (pthread_mutex_init(params->m_print, NULL) != 0)
		return (free_if_fail(params, forks, thread), 0);
	if (pthread_mutex_init(params->m_check, NULL) != 0)
		return (free_if_fail(params, forks, thread), 0);
	while (i < params->n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (free_all(params, forks, thread, i), 0);
		i++;
	}
	init_forks(params, forks);
	return (1);
}

int	init_params(t_param *params, pthread_t *thread, pthread_mutex_t *forks,
			char **av)
{
	int			i;
	static int	v;

	i = 0;
	v = 1;
	while (i < params->n_philo)
	{
		params[i].id_p = i + 1;
		params[i].death_time = ft_atoi(av[2]);
		params[i].eat_time = ft_atoi(av[3]);
		params[i].sleep_time = ft_atoi(av[4]);
		params[i].start_time = count_time();
		params[i].t_last_meal = count_time();
		params[i].v_check = &v;
		params[i].m_print = params->m_print;
		params[i].m_check = params->m_check;
		params[i].nb_t_must_eat = -2;
		if (av[5])
			params[i].nb_t_must_eat = ft_atoi(av[5]);
		if (params->death_time == 0 || params->eat_time == 0
			|| params->sleep_time == 0 || params->nb_t_must_eat == 0)
			return (free_all(params, forks, thread, params->n_philo), 0);
		i++;
	}
	return (1);
}
