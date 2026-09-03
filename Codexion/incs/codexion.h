#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum	e_action{
				COMPILE,
				DEBUG,
				REFACTOR,
}				t_action;

typedef enum	e_schedule{
				FIFO,
				LIFO,
				EDF,
}				t_schedule;

typedef unsigned int t_bool;

typedef struct	s_dongle{
	size_t		id;
	t_bool		is_taken;
	size_t		cooldown;
}				t_dongle;

typedef struct	s_coder{
	pthread_t	thread;
	size_t		id;
	t_action	action;
	t_bool		is_burnout;
	t_dongle	*left;
	t_dongle	*right;
	size_t		t_burnout;
	size_t		t_compile;
	size_t		t_debug;
	size_t		t_refactor;
	size_t		t_cooldown;
	size_t		t_total;
}				t_coder;

typedef struct	s_table{
	t_schedule	schedule;
	t_coder		**coders;
	t_dongle	**dongle;
	size_t		nbr_coders;
	size_t		nbr_dongles;
}				t_table;

	//		String Methods		//
int		ft_strlen(const char *s);
int 	ft_strcmp(const char *s1, const char *s2);
int 	ft_atoi(const char *nptr);

	//		Memory Methods		//
void 	*memset(void *s, int c, size_t n);

	//		Coder Methods		//
	//		Dongle Methods		//
	//		Table Methods		//
	//		Time Methods		//

/*
◦ timestamp_in_ms X has taken a dongle
◦ timestamp_in_ms X is compiling
◦ timestamp_in_ms X is debugging
◦ timestamp_in_ms X is refactoring
◦ timestamp_in_ms X burned out
*/

/*EXTERNAL ALLOWED FUNCTIONS:
pthread_create, pthread_join, pthread_mutex_init,
pthread_mutex_lock,
pthread_mutex_unlock, pthread_mutex_destroy,
pthread_cond_init,
pthread_cond_wait, pthread_cond_timedwait,
pthread_cond_signal,
pthread_cond_broadcast, pthread_cond_destroy,
gettimeofday, clock_gettime,
usleep, write, malloc, free, printf, fprintf,
strcmp, strlen, atoi, memset
*/

#endif /*CODEXION_H*/
