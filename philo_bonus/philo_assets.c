/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:03:07 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/01 14:54:06 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	senko_err(char *error)
{
	write(2, error, ft_strlen(error));
	return (EXIT_FAILURE);
}

t_micro_s_t	get_time_stamp(void)
{
	struct timeval	time_v;

	gettimeofday(&time_v, NULL);
	return (time_v.tv_sec * (t_micro_s_t)1000000 + time_v.tv_usec);
}

void	print_status(t_philosopher *philo)
{
	char	*str;
	
	str = NULL;
	if (!g_conf.run)
		return ;
	if (philo->status == EATING)
		str = "is EATING\n";
	else if (philo->status == SLEEPING)
		str = "is SLEEPING\n";
	else if (philo->status == THINKING)
		str = "is THINKING\n";
	else if (philo->status == DEAD)
		str = "is DEAD\n";
	else if (philo->status == TAKINGFORKS)
		str = "has taken a fork\n";
	sem_wait(g_conf.sem_out);
	ft_putnbr((get_time_stamp() - g_time_start) / 1000);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	ft_putstr_fd(str, 1);
	if (philo->status != DEAD)
		sem_post(g_conf.sem_out);
}

void	status(t_philosopher *philo, int stat)
{
	if (philo->status != DEAD)
		philo->status = stat;
}



void	*philo_sim(void *par)
{
	t_philosopher	*philo;

	philo = par;
	if (pthread_create(&philo->thread, NULL, supervisor, philo))
		exit(senko_err("Error\n"));
	while ((g_conf.nbr_end == -1 || philo->total_eated < g_conf.nbr_end)
		&& g_conf.run)
	{
		think(philo);
		take_fork(philo);
		eat(philo);
		put_forks(philo);
		philo_sleep(philo);
	}
	status(philo, DONE);
	return (NULL);
}
