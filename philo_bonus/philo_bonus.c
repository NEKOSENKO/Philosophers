/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:30:44 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/24 12:41:02 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	collect_data(int ac, char **av)
{
	g_conf.nbr_p = ft_atoi(av[1]);
	g_conf.t_die = ft_atoi(av[2]) * 1000;
	g_conf.t_eat = ft_atoi(av[3]) * 1000;
	g_conf.t_sleep = ft_atoi(av[4]) * 1000;
	g_conf.nbr_end = -1;
	if (ac == 6)
		g_conf.nbr_end = ft_atoi(av[5]);
	if (g_conf.nbr_p <= 0 || g_conf.t_die <= 0
		|| g_conf.t_die <= 0 || g_conf.t_sleep <= 0
		|| (ac == 6 && g_conf.nbr_end <= 0))
		return (senko_err("Error: Unvalid Argument\n"));
	return (EXIT_SUCCESS);
}

int	init_next()
{
	int	i;

	i = 0;
	g_conf.stop_write = FALSE;
	while (i < g_conf.nbr_p)
	{
		g_philosophers[i].id = i + 1;
		g_philosophers[i].is_dead = FALSE;
		g_philosophers[i].status = THINKING;
		g_philosophers[i].total_eated = 0;
		g_philosophers[i].t_last_eat = g_time_start;
		g_philosophers[i].pid = fork();
		if (g_philosophers[i].pid == 0)
			philo_sim(&g_philosophers[i]);
		else if (g_philosophers[i].pid < 0)
			return (senko_err("Error : Couldn't fork child"));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	phil_init(void)
{
	g_time_start = get_time_stamp();
	g_conf.run = TRUE;
	g_sema = sem_open("forks", O_CREAT, S_IRWXG, g_conf.nbr_p);
	g_conf.sem_out = sem_open( "output", O_CREAT, S_IRWXG, 1);
	g_conf.sem = sem_open("global", O_CREAT, S_IRWXG, 1);
	if (g_sema == SEM_FAILED || g_conf.sem_out == SEM_FAILED || g_conf.sem == SEM_FAILED)
		return (senko_err("Error : SEM_FAILED"));
	g_philosophers = malloc(g_conf.nbr_p * sizeof(t_philosopher));
	if (!g_philosophers)
		return (senko_err("Error : Failed to allocate memory"));
	if (init_next())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	proc_super()
{
	int	i;
	int	j;
	int	stat;

	i = 0;
	while (i < g_conf.nbr_p)
	{
		waitpid(-1, &stat, 0);
		if (WEXITSTATUS(stat) == 2)
		{
			j = 0;
			while (j < g_conf.nbr_p)
				kill(g_philosophers[j++].pid, SIGKILL);
			return (0);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 5 && ac != 6)
		return (senko_err("Error: Missing or too many arguments\n"));
	//sem_unlik x3 forks out global
	sem_unlink("forks");
	sem_unlink("output");
	sem_unlink("global");
	if (collect_data(ac, av))
		return (EXIT_FAILURE);
	if (phil_init() || proc_super())
	{
		//sem_unlik x3 forks out global
		sem_unlink("forks");
		sem_unlink("output");
		sem_unlink("global");
		return (EXIT_FAILURE);
	}
}
