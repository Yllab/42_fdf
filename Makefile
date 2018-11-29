# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/29 20:14:02 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf	

SRCSDIR   		=	srcs

SRCS			:=	$(SRCSDIR)/main.c			\
					$(SRCSDIR)/get_input.c		\
					$(SRCSDIR)/get_next_line.c	\

OBJSDIR   		=	objs

OBJS  			:= 	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

INCLUDES		=   -I libft/includes 			\
					-I includes					\
					-I minilibx_macos			\

LIBS			=	-L libft/ -lft				\
					-L minilibx_macos/ -lmlx 	\
					-framework OpenGL			\
					-framework AppKit

CFLAGS			+=	-Wall -Werror -Wextra

CC				=	gcc

all				:	$(NAME)

$(NAME)			: 	$(OBJS)
					make -C minilibx_macos/
					make -C libft/
					$(CC) -o $@ $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJS)

$(OBJS)			: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY			:	clean
clean			:
					rm -f $(OBJS)
					make clean -C minilibx_macos/
					make clean -C libft/

.PHONY			:	fclean
fclean			:	clean
					rm -f $(NAME)
					make fclean -C libft/

re				:	fclean all
