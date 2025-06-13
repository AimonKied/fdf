# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 13:07:22 by swied             #+#    #+#              #
#    Updated: 2025/06/13 19:29:54 by swied            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -framework OpenGL -framework AppKit
INCD := include
SRCD := src
OBJD := obj
LIBFT_DIR := $(INCD)/libft
LIBFT := $(LIBFT_DIR)/libft.a
MLX_DIR := .
MLX := libmlx.dylib

# Colors
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
NC := \033[0m # No Color

SRCS :=			$(SRCD)/main.c \
				$(SRCD)/utils.c \
				$(SRCD)/parsing.c \
				$(SRCD)/check.c \
				$(SRCD)/offset.c \
				$(SRCD)/rotate.c \
				$(SRCD)/find_xy.c \
				$(SRCD)/scale.c \
				$(SRCD)/move.c \
				$(SRCD)/draw.c \
				$(SRCD)/init_minilibx.c

OBJS := $(SRCS:$(SRCD)/%.c=$(OBJD)/%.o)

all: $(NAME)

$(LIBFT):
	@printf "$(YELLOW)Building libft library...$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	@printf "$(YELLOW)Compiling $<...$(NC)\n"
	@$(CC) $(CFLAGS) -I $(INCD) -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(NC)\n"

$(OBJD):
	mkdir -p $(OBJD)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L. -lmlx $(LDFLAGS) -o $(NAME)
	@printf "$(GREEN)Executable $(NAME) built successfully!$(NC)\n"

clean:
	@printf "$(RED)Cleaning object files...$(NC)\n"
	rm -rf $(OBJD)
	@printf "$(GREEN)Object files cleaned!$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@printf "$(RED)Cleaning library and executable...$(NC)\n"
	rm -f $(NAME)
	@printf "$(GREEN)Executable cleaned!$(NC)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re