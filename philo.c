/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:04:56 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 19:24:12 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_param *params, char *msg)
{
	pthread_mutex_lock(params->m_print);
	if (*params->v_died == 1)
		printf("%ld %d %s\n", ft_timestamp(params->start_time),
			params->id_p, msg);
	pthread_mutex_unlock(params->m_print);
}

void	count_meals(t_param *params)
{
	pthread_mutex_lock(params->m_check);
	if (params->nb_t_must_eat != -2)
		params->nb_t_must_eat--;
	pthread_mutex_unlock(params->m_check);
}

void	philo_eat(t_param *params)
{
	print_msg(params, "is eating");
	pthread_mutex_lock(params->m_check);
	params->t_last_meal = count_time();
	pthread_mutex_unlock(params->m_check);
	ft_usleep(params->eat_time, params);
	count_meals(params);
}

void	philo_sleep(t_param *params)
{
	print_msg(params, "is sleeping");
	ft_usleep(params->sleep_time, params);
}

void	*philo_routine(void *arg)
{
	t_param	*params;
	int		v;

	params = (t_param *)arg;
	if(params->id_p % 2 == 0)
		usleep(100);
	v = 1;
	while (v)
	{
		print_msg(params, "is thinking");
		pthread_mutex_lock(params->right_fork);
		print_msg(params, "has taken a fork");
		if (params->n_philo == 1)
			return (NULL);
		pthread_mutex_lock(params->left_fork);
		print_msg(params, "has taken a fork");
		philo_eat(params);
		pthread_mutex_unlock(params->right_fork);
		pthread_mutex_unlock(params->left_fork);
		philo_sleep(params);
		pthread_mutex_lock(params->m_check);
		v = *params->v_died;
		pthread_mutex_unlock(params->m_check);
	}
	return (NULL);
}
