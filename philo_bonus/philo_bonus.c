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

#include "philo.h"

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

int	phil_init(void)
{
	int	i;

	g_time_start = get_time_stamp();
	g_conf.run = TRUE;
	g_sema = sem_open("forks", O_CREAT, S_IRWXG, g_conf.nbr_p);
	g_conf.sem_out = sem_open( "output", O_CREAT, S_IRWXG, 1);
	g_conf.sem = sem_open("output", O_CREAT, S_IRWXG, 1);
	
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
	if (collect_data(ac, av))
		return (EXIT_FAILURE);
	if (phil_init() || proc_super())
	{
		//sem_unlik x3 forks out global
		return (EXIT_FAILURE);
	}
}
