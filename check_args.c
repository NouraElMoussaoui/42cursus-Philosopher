/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:42:32 by nel-mous          #+#    #+#             */
/*   Updated: 2023/04/27 18:11:26 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	oops(void)
{
	write(2, "INVALID ARGUMENT\n", 17);
	return ;
}

int	is_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char **av, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if (av[i][0] == '+')
			j++;
		if (!ft_isdigit(av[i][j]) || ft_atoi(av[i]) > 2147483647
		|| ft_atoi(av[i]) < -2147483648)
			return (1);
		j++;
	}
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_space(av[i]) == 1)
		{
			oops();
			return (1);
		}
		if (is_number(av, i) == 1)
		{
			oops();
			return (1);
		}
		i++;
	}
	return (0);
}
