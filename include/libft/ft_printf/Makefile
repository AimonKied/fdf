# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 16:18:56 by swied             #+#    #+#              #
#    Updated: 2025/06/10 15:12:55 by swied            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_printf.c \
		ft_execute.c \
		ft_putchar.c \
		ft_c.c \
		ft_s.c \
		ft_p.c \
		ft_i.c \
		ft_u.c \
		ft_x.c \
		ft_capital_x.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all