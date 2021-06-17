/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:30:44 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/17 19:44:07 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	collect_data(int ac, char **av)
{
	g_conf.nbr_p = ft_atoi(av[1], 0);
	g_conf.t_die = ft_atoi(av[2], 0) * 1000;
	g_conf.t_eat = ft_atoi(av[3], 0) * 1000;
	g_conf.t_sleep = ft_atoi(av[4], 0) * 1000;
	g_conf.nbr_end = -1;
	if (ac == 6)
		g_conf.nbr_end = ft_atoi(av[5], 0);
	if (g_conf.nbr_p <= 0 || g_conf.t_die <= 0
		|| g_conf.t_die <= 0 || g_conf.t_sleep <= 0
		|| (ac == 6 && g_conf.nbr_end <= 0))
		return (senko_err("Error: Unvalid Argument\n"));
	return (EXIT_SUCCESS);
}

int phil_init_next()
{
	int i;

	i = 0;
	while (i < g_conf.nbr_p)
	{
		g_philosophers[i].id = i + 1;
		g_philosophers[i].is_dead = FALSE;
		g_philosophers[i].status = THINKING;
		g_philosophers[i].t_last_eat = g_time_start;
		if (pthread_create(&g_philosophers[i].philo_th, NULL, &philo_sim, &g_philosophers[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	phil_init()
{
	int i;

	g_time_start = get_time_stamp();
	g_conf.run = TRUE;
	g_forks = (pthread_mutex_t *)malloc((g_conf.nbr_p * sizeof(pthread_mutex_t)));
	if (!g_forks)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&g_conf.mutex, NULL)
		|| pthread_mutex_init(&g_conf.mutex_out, NULL)
		|| pthread_mutex_init(&g_conf.death, NULL))
		return (EXIT_FAILURE);
	i = 0;
	while (i < g_conf.nbr_p)
		if (pthread_mutex_init(&g_forks[i++], NULL))
			return (EXIT_FAILURE);
	g_philosophers = malloc(g_conf.nbr_p * sizeof(t_philosopher));
	if (!g_philosophers)
		return (EXIT_FAILURE);
	if (phil_init_next())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 5 && ac != 6)
		return (senko_err("Error: Missing or too many arguments\n"));
	//collect data
	if (collect_data(ac, av))
		return (EXIT_FAILURE);
	//init and unlock mutex out
	if (phil_init() /* || supervisor */)
	{
		pthread_mutex_unlock(&g_conf.mutex_out);
		return (EXIT_FAILURE);
	}
	// return (EXIT_SUCCESS);
}
