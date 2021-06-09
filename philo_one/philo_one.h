/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:21:52 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/09 13:20:05 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <pthread.h>
# include<semaphore.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

# define FALSE 0
# define TRUE 1
# define EATING 2
# define THINKING 3
# define SLEEPING 4
# define DEAD 5
# define TAKINGFORKS 6
# define LEAVINGFORKS 7
# define DONE 8

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		ft_atoi(const char *str, int i);
int		senko_err(char *error);

#endif