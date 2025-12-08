# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 16:04:22 by mfarhan          #+#    #+#              #
#    Updated: 2025/11/10 12:33:25 by mfarhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_isalpha \
	  ft_isdigit \
	  ft_isalnum \
	  ft_isascii \
	  ft_isprint \
	  ft_strlen \
	  ft_memset \
	  ft_bzero \
	  ft_memcpy \
	  ft_memmove \
	  ft_strlcpy \
	  ft_strlcat \
	  ft_tolower \
	  ft_toupper \
	  ft_strchr \
	  ft_strrchr \
	  ft_strncmp \
	  ft_memcmp \
	  ft_memchr \
	  ft_strnstr \
	  ft_atoi \
	  ft_calloc \
	  ft_strdup \
	  ft_substr \
	  ft_strjoin \
	  ft_strtrim \
	  ft_split \
	  ft_itoa \
	  ft_strmapi \
	  ft_striteri \
	  ft_putchar_fd \
	  ft_putnbr_fd \
	  ft_putendl_fd \
	  ft_putstr_fd

BONUS_SRC = ft_lstnew \
			ft_lstadd_front \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstmap \
			ft_lstsize \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))
BONUS_SRCS = $(addsuffix .c, $(BONUS_SRC))
BONUS_OBJS = $(addsuffix .o, $(BONUS_SRC))

.c.o: $(SRCS) $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re bonus
