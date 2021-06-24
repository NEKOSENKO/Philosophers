# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 13:00:21 by mbrija            #+#    #+#              #
#    Updated: 2021/06/24 14:37:17 by mbrija           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=philo.c libft_utils.c philo_assets.c simulation.c

FLAGS=-Wextra -Wall -Werror

NAME=philo

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
