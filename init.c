/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:50:54 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 18:36:56 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_param *params, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	(void) forks;
	(void) params;
	params->m_print = malloc(sizeof(pthread_mutex_t));
	params->m_check = malloc(sizeof(pthread_mutex_t));
	while (i < params->n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < params->n_philo)
	{
		params[i].right_fork = &forks[i];
		params[i].left_fork = &forks[(i + 1) % params->n_philo];
		i++;
	}
	pthread_mutex_init(params->m_print, NULL);
	pthread_mutex_init(params->m_check, NULL);
}

void	init_params(t_param *params, char **av)
{
	int	i;
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
		params[i].v_died = &v;
		params[i].m_print = params->m_print;
		params[i].m_check = params->m_check;
		params[i].nb_t_must_eat = -2;
		if (av[5])
			params[i].nb_t_must_eat = ft_atoi(av[5]);
		i++;
	}
}
