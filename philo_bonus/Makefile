# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 13:00:21 by mbrija            #+#    #+#              #
#    Updated: 2021/07/01 14:28:52 by mbrija           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=philo_bonus.c libft_utils.c philo_assets.c simulation.c senko_utils.c

FLAGS=-Wextra -Wall -Werror

NAME=philo_bonus

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
