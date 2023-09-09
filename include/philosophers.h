/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:01:12 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:48:07 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

// constants error messages
# define ERROR_MEAL "\033[31mError\nMeals must be a positive integer\033[0m\n"
# define ERROR_ARGC "\033[31mError\nWrong number of arguments.\033[0m\n"
# define ERROR_ARGV "\033[31mError\nExpected one character at least.\033[0m\n"
# define ERROR_ARGV2 "\033[31mError\nOnly numbers positive are allowed.\033[0m\n"
# define ERROR_MALLOC_FORKS "\033[31mError\nWhen calloc memory for forks.\033[0m\n"
# define ERROR_MALLOC_PHILO "\033[31mError\nWhen calloc memory for philos.\033[0m\n"
# define ERROR_MUTEX1 "\033[31mError\nWhen init mutex info_lock.\033[0m\n"
# define ERROR_MUTEX2 "\033[31mError\nWhen init mutex forks.\033[0m\n"
# define ERROR_MUTEX3 "\033[31mError\nWhen init mutex philo.\033[0m\n"
# define ERROR_THREAD1 "\033[31mError\nWhen creating threads.\033[0m\n"
# define ERROR_THREAD2 "\033[31mError\nWhile joining threads.\033[0m\n"
# define ERROR_PHILO "\033[31mError\nPhilo must be between 1 and 200.\033[0m\n"
# define ERROR_DIE "\033[31mError\nTime to die must be a positive int.\033[0m\n"
# define ERROR_EAT "\033[31mError\nTime to eat must be a positive int.\033[0m\n"
# define ERROR_SLEEP "\033[31mError\nTime to sleep must be a positive int.\033[0m\n"
# define ERROR_THREAD "\033[31mError\nWhen create thread.\033[0m\n"
# define ERROR_GETTIME "\033[31mError\nWhen get time.\033[0m\n"

//constants messages
# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

//constants colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

// Structures
typedef struct s_info
{
	int					philo_count;
	int					all_filled;
	int					dead;
	int					meals_to_eat;
	unsigned long long	time_die;
	unsigned long long	time_eat;
	unsigned long long	time_sleep;
	unsigned long long	start_time;
	struct s_philo		*philos;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		info_lock;
}	t_info;

typedef struct s_philo
{
	int					eating;
	int					filled;
	int					pending_meals;
	int					has_forks;
	unsigned int		philo_id;
	unsigned int		rigth_fork_id;
	unsigned int		left_fork_id;
	unsigned long long	last_meal;
	unsigned long long	time_of_death;
	struct s_info		*info;
	pthread_mutex_t		philo_lock;
}	t_philo;

// Utils
/**
 * @brief Convert a string to an integer
 * 
 * @param str string to be converted
 * @return int integer converted
 */
int					ft_atoi(const char *str);
/**
 * @brief check if the character is a digit
 * 
 * @param c character to be checked
 * @return int if is a digit return 1, if not return 0.
 */
int					ft_isdigit(int c);
/**
 * @brief assign memory to a pointer and initialize it to 0
 * 
 * @param nmemb number of elements
 * @param size size of each element
 * @return void* pointer to the allocated memory
 */
void				*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief clean the struct info
 * 
 * @param info struct to be cleaned
 */
void				ft_clean_info(t_info *info);
/**
 * @brief get the time in milliseconds
 * 
 * @return unsigned long long time in milliseconds
 */
unsigned long long	ft_get_time(void);

// Checkers
/**
 * @brief check if the arguments is a number, is a valid value and the number of
 * arguments.
 * 
 * @param argc number of arguments
 * @param argv arguments to be checked
 * @return int return 1 if is a valid value, 0 if not.
 */
int					ft_check_args(int argc, char **argv);
/**
 * @brief check if the value of the arguments is valid.
 * 
 * @param info 
 * @return int 
 */
int					ft_check_value_info(t_info *info);
/**
 * @brief check if the philos ate the number of meals.
 * 
 * @param info struct with the information of the program
 * @param id identifier of the philo
 * @return int return 1 if the philo ate the number of meals, 0 if not.
 */
int					ft_check_philos_ate(t_info *info, int id);
/**
 * @brief check if the philo is filled.
 * 
 * @param info struct with the information of the program
 * @param id identifier of the philo
 * @return int return 1 if the philo is filled, 0 if not.
 */
int					ft_check_any_filled(t_info *info, int id);
/**
 * @brief check if one of the philos are dead.
 * 
 * @param info struct with the information of the program
 * @param id identifier of the philo
 * @return int return 1 if one of the philos are dead, 0 if not.
 */
int					ft_check_philos_dead(t_info *info, int id);
/**
 * @brief check if the philo is dead.
 * 
 * @param info struct with the information of the program
 * @param id identifier of the philo
 * @return int return 1 if the philo is dead, 0 if not.
 */
int					ft_check_any_die(t_info *info, int id);

// Initialization
/**
 * @brief initialize the mutexes, thread and the info struct.
 * 
 * @param info struct with the information of the program
 * @param argv arguments of the program
 * @param argc number of arguments
 * @return int return 1 if the initialization is correct, 0 if not.
 */
int					ft_init(t_info *info, char **argv, int argc);
/**
 * @brief initialize the mutexes for the forks.
 * 
 * @param info struct with the information of the program
 * @return int return 1 if the initialization is correct, 0 if not.
 */
int					ft_init_forks(t_info *info);
/**
 * @brief initialize the data and mutexes for the philos.
 * 
 * @param info struct with the information of the program
 * @return int return 1 if the initialization is correct, 0 if not.
 */
int					ft_init_philos(t_info *info);
/**
 * @brief execute the routine of the philo depending of the id 
 * of the philo and the number of philos.
 * 
 * @param thread_struct struct with the information of the philo
 * @return void* return NULL
 */
void				*ft_init_routine(void *thread_struct);

// Controllers
/**
 * @brief controller of the program.
 * 
 * @param info struct with the information of the program
 * @return int return 1 if the controller is correct, 0 if not.
 */
int					ft_init_philosopher(t_info *info);
/**
 * @brief initialize the threads with the routine of the philos.
 * 
 * @param info struct with the information of the program
 * @return int return 1 if the initialization is correct, 0 if not.
 */
int					ft_start_all_threads(t_info *info);
/**
 * @brief stop all the threads joining them.
 * 
 * @param info struct with the information of the program
 * @return int return 1 if the stop is correct, 0 if not.
 */
int					ft_stop_all_threads(t_info *info);
/**
 * @brief execute the routine of the one philo. pensar, comer, dormir.
 * 
 * @param philo struct with the information of the philo
 * @param info struct with the information of the program
 * @return int return 0 if the philo is dead, 1 if not.
 */
int					ft_routine(t_philo *philo, t_info *info);
/**
 * @brief stop the philo for certain time or until one of the philos are dead.
 * 
 * @param time time to stop the philo
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 * @return int return 1 if the stop is correct, 0 if not or philo are dead
 * while are stopped.
 */
int					ft_sleep_philos(unsigned long long time, t_info *info,
						t_philo *philo);
/**
 * @brief lock the mutex of the philo fork right.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 */
void				ft_take_fork_rigth(t_info *info, t_philo *philo);
/**
 * @brief lock the mutex of the philo fork left.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 */
void				ft_take_fork_left(t_info *info, t_philo *philo);
/**
 * @brief unlock the mutex of the philo fork right and set eating 0.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 */
void				ft_drop_fork_rigth(t_info *info, t_philo *philo);
/**
 * @brief unlock the mutex of the philo fork left and set eating 0.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 */
void				ft_drop_fork_left(t_info *info, t_philo *philo);
/**
 * @brief print the message died.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 */
void				ft_print_died(t_info *info, t_philo *philo);
/**
 * @brief print the message of the philo.
 * 
 * @param info struct with the information of the program
 * @param philo struct with the information of the philo
 * @param msg message to be printed
 * @param color color of the message
 */
void				ft_print_msg(t_info *info, t_philo *philo,
						char *msg, char *color);

#endif
