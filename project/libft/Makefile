# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 20:34:04 by nbirdper          #+#    #+#              #
#    Updated: 2021/01/29 22:37:19 by nbirdper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

C_FLAG 	= -Wall -Wextra -Werror

HEADER 	= libft.h

SRCS 	= ft_bzero.c ft_calloc.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c \
	   ft_memcmp.c \
	   ft_isascii.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c \
	   ft_atoi.c ft_strdup.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlen.c\
	   ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   \
	   ft_isspace.c ft_isempty_str.c ft_foreach.c\
		 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c


OBJS:= $(SRCS:c=o)

OBJS_BONUS:= $(SRCS_BONUS:c=o)

all: 	$(NAME)

bonus: 	$(OBJS) $(OBJS_BONUS)
	#ar rc $(NAME) $^
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c $(HEADER)
	gcc $(C_FLAG) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
