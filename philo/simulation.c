/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:19:42 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/01 12:51:12 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void senko_usleep(int time)
{
	int start;
	int current;
	int final;

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
			break;
	}
}

void think(t_philosopher *philo)
{
	status(philo, THINKING);
	print_status(philo);
}

void take_fork(t_philosopher *philo)
{
	pthread_mutex_unlock(&g_conf.mutex);
	status(philo, TAKINGFORKS);
	pthread_mutex_lock(&g_forks[philo->id - 1]);
	print_status(philo);
	pthread_mutex_lock(&g_forks[philo->id % g_conf.nbr_p]);
	print_status(philo);
}

void eat(t_philosopher *philo)
{
	status(philo, EATING);
	print_status(philo);
	philo->total_eated++;
	philo->t_last_eat = get_time_stamp();
	senko_usleep(g_conf.t_eat);
	while (get_time_stamp() - philo->t_last_eat < g_conf.t_eat)
		;
}

void put_forks(t_philosopher *philo)
{
	status(philo, SLEEPING);
	print_status(philo);
	pthread_mutex_unlock(&g_forks[philo->id - 1]);
	pthread_mutex_unlock(&g_forks[philo->id % g_conf.nbr_p]);
}

void philo_sleep(t_philosopher *philo)
{
	philo->start_sleep = get_time_stamp();
	status(philo, SLEEPING);
	senko_usleep(g_conf.t_sleep);
	while (get_time_stamp() - philo->start_sleep < g_conf.t_sleep)
		;
}
