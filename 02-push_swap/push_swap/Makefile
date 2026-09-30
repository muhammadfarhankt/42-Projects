# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/30 17:19:35 by mfarhan           #+#    #+#              #
#    Updated: 2026/09/30 17:19:59 by mfarhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)
NAME = push_swap
BONUS_NAME = checker
HEADER = push_swap.h
HEADER_BONUS = ./bonus/checker.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = ./main.c ./utils/ft_split.c ./utils/ft_atoi.c \
       ./utils/error.c ./utils/ft_lstnew.c ./utils/ft_lstadd_back.c \
       ./utils/ft_lstsize.c ./utils/ft_lstlast.c \
       ./rules/swap.c ./rules/rotate.c ./rules/reverse_rotate.c \
       ./rules/push.c ./rules/five_or_less.c ./rules/sorting.c \
	   ./utils/turk_utils_1.c ./utils/turk_utils_2.c ./utils/turk_utils_3.c \
	   ./utils/five_utils.c 


BONUS = ./bonus/checker.c \
		./bonus/gnl/get_next_line.c \
		./bonus/gnl/get_next_line_utils.c  \
		./bonus/rules/push_bonus.c  \
		./bonus/rules/reverse_rotate_bonus.c  \
		./bonus/rules/rotate_bonus.c  \
		./bonus/rules/swap_bonus.c  \
		./bonus/utils/error_bonus.c  \
		./bonus/utils/ft_atoi_bonus.c  \
		./bonus/utils/ft_lstadd_back_bonus.c  \
		./bonus/utils/ft_lstlast_bonus.c  \
		./bonus/utils/ft_lstnew_bonus.c  \
		./bonus/utils/ft_lstsize_bonus.c  \
		./bonus/utils/ft_split_bonus.c  \
		./bonus/utils/ft_strncmp.c \
		./bonus/utils/utils_bonus.c \
		./bonus/fixed.c

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

./%.o: ./%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) -o $(BONUS_NAME)

bonus/%.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY:	clean 
