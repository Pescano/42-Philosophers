# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 18:56:24 by paescano          #+#    #+#              #
#    Updated: 2023/09/09 12:49:34 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

CFILES = checkers/check_args.c checkers/check_philo_status.c checkers/check_values.c \
		controllers/actions_threads.c controllers/control_threads.c controllers/forks_actions.c \
		controllers/routine.c controllers/sleep_philos.c initialization/init_forks.c \
		initialization/init_philos.c initialization/init_routine.c initialization/initialization.c \
		utils/ft_atoi.c utils/ft_calloc.c utils/ft_clean_info.c utils/ft_get_time.c \
		utils/ft_isdigit.c utils/ft_print_console.c philosophers.c

INCLUDES = include/philosophers.h

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@echo $(G)Finished Compiling of [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed following objects: [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) $(INCLUDES)

.PHONY: all clean fclean re norma