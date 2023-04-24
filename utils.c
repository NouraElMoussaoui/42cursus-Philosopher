/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:19 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 18:44:11 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long long	ft_atoi(const char *s)
{
	char		*str;
	int			i;
	long long			x;
	int			sign;

	str = (char *)s;
	i = 0;
	x = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') && ((x * sign) >= -2147483648 && (x * sign) <= 2147483647))
	{
		x = x * 10 + str[i] - '0';
		i++;
	}
	return (x * sign);
}

void	free_mutexes(t_param *params, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < params->n_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(params->m_print);
	pthread_mutex_destroy(params->m_check);
	free(params->m_print);
	free(params->m_check);
}

void	free_all(t_param *params, pthread_mutex_t *forks, pthread_t *thread)
{
	free_mutexes(params, forks);
	free(params);
	free(thread);
	free(forks);
}
