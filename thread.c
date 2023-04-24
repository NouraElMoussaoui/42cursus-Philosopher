/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:33:09 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 19:24:28 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_param *params, int i)
{
	pthread_mutex_lock(params->m_print);
	*params->v_died = 0;
	printf("%ld %d died\n", ft_timestamp(params->start_time), i + 1);
	pthread_mutex_unlock(params->m_print);
	pthread_mutex_unlock(params->m_check);
}

void	check_meals(t_param *params)
{
	pthread_mutex_lock(params->m_print);
	*params->v_died = 0;
	pthread_mutex_unlock(params->m_print);
	pthread_mutex_unlock(params->m_check);
}

void	ft_check(t_param *params)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(params->m_check);
		if (count_time() - (params[i].t_last_meal) >= params[i].death_time)
		{
			check_death(params, i);
			break ;
		}
		if (params[i].nb_t_must_eat == -1)
		{
			check_meals(params);
			break ;
		}
		pthread_mutex_unlock(params->m_check);
		i = (i + 1) % params->n_philo;
	}
}

void	wait_exec(t_param *params, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < params->n_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

void	create_philo(t_param *params, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < params->n_philo)
	{
		if (pthread_create(&thread[i], NULL, &philo_routine, &params[i]) != 0)
			return ;
		usleep(10);
		i++;
	}
	ft_check(params);
	wait_exec(params, thread);
}