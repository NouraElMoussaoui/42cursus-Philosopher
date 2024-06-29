/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:50:21 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/29 13:12:27 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	count_time(void)
{
	struct timeval	current_time;
	long int		sec;
	long int		usec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec * 1000;
	usec = current_time.tv_usec / 1000;
	return (sec + usec);
}

long int	ft_timestamp(long int time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - time);
}

void	ft_usleep(long int time, t_param *params)
{
	long int	current_time;
	int			v;

	current_time = count_time();
	v = 1;
	while (count_time() < current_time + time && v)
	{
		usleep(100);
		pthread_mutex_lock(params->m_check);
		v = *params->v_check;
		pthread_mutex_unlock(params->m_check);
	}
}
