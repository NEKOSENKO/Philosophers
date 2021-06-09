/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:30:44 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/09 14:53:04 by mbrija           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 5 && ac != 6)
		return (senko_err("Error: Missing or too many arguments\n"));
	//collect data
	if (collect_data(ac, av))
		return (EXIT_FAILURE);
	//init and unlock mutex out
	return (EXIT_SUCCESS);
}
