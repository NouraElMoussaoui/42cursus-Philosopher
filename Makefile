# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 09:26:05 by nel-mous          #+#    #+#              #
#    Updated: 2023/05/03 15:26:00 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  main.c philo.c utils.c check_args.c init.c thread.c manage_time.c

OBJS	=$(SRCS:.c=.o)

NAME	= philo

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -pthread

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
