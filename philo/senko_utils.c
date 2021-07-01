/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   senko_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:58:53 by mbrija            #+#    #+#             */
/*   Updated: 2021/07/01 12:58:58 by mbrija           ###   ########.fr       */
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
