#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 10:14:19 by jcarra            #+#    #+#              #
#    Updated: 2016/12/05 13:56:00 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_select

SRC			=	ft_listlast.c \
				ft_findit.c \
				ft_input.c \
				ft_free_list.c \
				ft_display.c \
				ft_init.c \
				ft_select_tools.c \
				ft_select.c \
				ft_listlen.c \
				ft_deldata.c \
				ft_remove.c \
				ft_add.c \
				ft_new.c \
				ft_initlist.c \
				ft_main.c

LIB			=	libft.a

DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	library/

SRCS		=	$(SRC:%=$(DIRSRC)%)
OBJS		=	$(SRC:.c=.o)
LIBS		=	$(LIB:%=$(DIRLIB)%)

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC) -I./$(DIRLIB)$(DIRINC)
LFLAGS		=	-lncurses

CC			=	gcc
RM			=	rm -f
ECHO		=	printf
MAKE		=	make -C


all		:		$(NAME)

$(NAME)	:
				@$(MAKE) $(DIRLIB)
				@$(CC) $(CFLAGS) -c $(SRCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(LFLAGS)
				@$(ECHO) '\033[32m> Compiled\n\033[0m'

clean	:
				@$(MAKE) $(DIRLIB) clean
				@$(RM) $(OBJS)
				@$(ECHO) '\033[31m> Directory cleaned\n\033[0m'

fclean	:		clean
				@$(MAKE) $(DIRLIB) fclean
				@$(RM) $(NAME)
				@$(ECHO) '\033[31m> Remove executable\n\033[0m'

re		:		fclean all

.PHONY	:		all clean fclean re
