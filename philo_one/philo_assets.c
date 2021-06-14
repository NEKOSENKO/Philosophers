/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:03:07 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/14 12:05:40 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	senko_err(char *error)
{
	write(2, error, ft_strlen(error));
	return (EXIT_FAILURE);
}

t_micro_s_t get_time_stamp()
{
	struct timeval	time_v;
	
	gettimeofday(&time_v, NULL);
	return (time_v.tv_sec * (t_micro_s_t)1000000 + time_v.tv_usec);
}

void	*philo_sim(void *par)
{
	t_philosopher *philo;
	
	philo = par;
	pthread_mutex_lock(&g_conf.mutex);
	while ((g_conf.nbr_end == - 1 || philo->total_eated < g_conf.nbr_end)
	&& g_conf.run)
	{
		//think
		//forks
		//eat
		//stop_forks
		//sleep
	}
	//end_stat
	pthread_mutex_unlock(&g_conf.mutex);
	return (NULL);
}
