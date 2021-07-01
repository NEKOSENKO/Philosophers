/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:19:42 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/01 14:48:46 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	think(t_philosopher *philo)
{
	status (philo, THINKING);
	print_status(philo);
	sem_wait(g_conf.sem);
}

void	take_fork(t_philosopher *philo)
{
	sem_wait(g_sema);
	sem_wait(g_sema);
	status(philo, TAKINGFORKS);
	print_status(philo);	
	print_status(philo);
	sem_post(g_conf.sem);	
}

void	eat(t_philosopher *philo)
{
	status(philo, EATING);
	print_status(philo);
	philo->total_eated++;
	philo->t_last_eat = get_time_stamp();
	senko_usleep(g_conf.t_eat);
	while (get_time_stamp() - philo->t_last_eat > g_conf.t_eat)
			;
}

void	put_forks(t_philosopher *philo)
{
	status(philo, SLEEPING);
	print_status(philo);
	sem_post(g_sema);
	sem_post(g_sema);
}

void	philo_sleep(t_philosopher *philo)
{
	philo->start_sleep = get_time_stamp();
	status(philo, SLEEPING);
	senko_usleep(g_conf.t_sleep);
	while (get_time_stamp() - philo->start_sleep < g_conf.t_sleep)
			;
}
