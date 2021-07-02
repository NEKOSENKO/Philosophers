/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   senko_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:28:40 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/02 15:22:34 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	senko_usleep(int time)
{
	int	start;
	int	current;
	int	final;

	start = get_time_stamp();
	if (time > 60000)
		usleep(time - 20000);
	else
		usleep(time);
	while (1)
	{
		current = get_time_stamp();
		final = current - start;
		if (final >= time)
			break ;
	}
}

void	*supervisor(void *para)
{
	t_philosopher	*philo;

	philo = para;
	while (philo->status != 8)
	{
		if ((philo->status != EATING && get_time_stamp()
				- philo->t_last_eat > g_conf.t_die)
			|| philo->is_dead)
		{
			philo->status = DEAD;
			print_status(philo);
			g_conf.run = FALSE;
			exit(2);
		}
	}
	return (NULL);
}
