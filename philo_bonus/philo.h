/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:21:52 by mbrija            #+#    #+#             */
/*   Updated: 2021/06/30 14:54:54 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
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

typedef long	t_micro_s_t;

typedef struct s_conf
{
	int				nbr_p;
	int				run;
	int				stop_write;
	t_micro_s_t		t_die;
	t_micro_s_t		t_eat;
	t_micro_s_t		t_sleep;
	int				nbr_end;
	sem_t			*sem;
	sem_t			*sem_out;
}				t_conf;

typedef struct s_philosopher
{
	int			id;
	int			status;
	int			total_eated;
	int			is_dead;
	pthread_t	thread;
	pthread_t	philo_th;
	pid_t		pid;
	t_micro_s_t	t_last_eat;
	t_micro_s_t	start_sleep;
}				t_philosopher;

sem_t			*g_sema;
t_philosopher	*g_philosophers;
t_micro_s_t		g_time_start;
t_conf			g_conf;

void		ft_putchar_fd(char c, int fd);
void		ft_putnbr(int n);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *s);
int			ft_atoi(const char *str);
int			senko_err(char *error);
int			collect_data(int ac, char **av);
void		*philo_sim(void *par);
t_micro_s_t	get_time_stamp(void);
void		status(t_philosopher *philo, int stat);
void		print_status(t_philosopher *philo);
void		think(t_philosopher *philo);
void		take_fork(t_philosopher *philo);
void		eat(t_philosopher *philo);
void		put_forks(t_philosopher *philo);
void		philo_sleep(t_philosopher *philo);
int			supervisor(void);
int			proc_super(void);

#endif