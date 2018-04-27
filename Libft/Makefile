# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theogell <theogell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 17:55:25 by theogell          #+#    #+#              #
#    Updated: 2018/04/20 23:05:51 by theogell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
MKLIB = ar rc
RANLIB = ranlib
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_todigit.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi.c \
	ft_isascii.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_bzero.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strnew.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strdel.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_word_count.c \
	ft_word_len.c \
	ft_strsplit.c \
	ft_strjoin.c \
	ft_strsub.c \
	ft_is_whitespace.c \
	ft_strtrim.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstadd.c \
	ft_lstmap.c \
	ft_itoa.c
	
OBJ = $(SRC:.c=.o)
INC = libft.h
OK_GCC = @echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
OK_CLEAN = @echo "\033[33;01m Objects have been deleted.\033[0m"
BIN_DEL = @echo "\033[31;01m Binary has been deleted.\033[31;01m"

$(NAME): $(OBJ)
		@$(MKLIB) $(NAME) $(OBJ)
		@$(RANLIB) $(NAME)

%.o: %.c
		$(OK_GCC)
		@$(CC) -I $(INC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(OK_CLEAN)
		@$(RM) $(OBJ)

fclean: clean
			$(BIN_DEL)
			@$(RM) $(NAME)

re: fclean all
