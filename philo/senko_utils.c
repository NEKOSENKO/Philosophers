/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   senko_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:58:53 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/03 19:28:32 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	senko_usleep(int time)
{
	int	start;
	int	current;
	int	final;

	start = get_time_stamp();
	usleep(time - 20000);
	while (1)
	{
		current = get_time_stamp();
		final = current - start;
		if (final >= time)
			break ;
	}
}

void	supervisor_hack(int nbr_p, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < nbr_p)
	{
		pthread_join(philos[i].philo_th, NULL);
		i++;
	}
}

int	supervisor_hack_2(int i)
{
	g_conf.run = FALSE;
	g_philosophers[i].status = DEAD;
	print_status(&g_philosophers[i]);
	return (EXIT_SUCCESS);
}
