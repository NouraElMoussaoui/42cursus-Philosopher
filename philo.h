/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:26:13 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/24 18:37:26 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_param
{
	int				id_p;
	int				n_philo;
	long int		death_time;
	long int		eat_time;
	long int		sleep_time;
	long int		start_time;
	long int		nb_t_must_eat;
	long int		t_last_meal;
	int				*v_died;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_param;

long long			ft_atoi(const char *s);
int					ft_isdigit(int c);
void				*philo_routine(void *arg);
long int			count_time(void);
long int			ft_timestamp(long int time);
void				oops(void);
int					check_args(char **av);
void				init_mutex(t_param *params, pthread_mutex_t *forks);
void				create_philo(t_param *params, pthread_t *thread);
void				init_params(t_param *params, char **av);
void				ft_usleep(long int time, t_param *params);
void				free_all(t_param *params, pthread_mutex_t *forks,
						pthread_t *thread);
#endif