# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/29 13:35:54 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf	

SRCSDIR   		=	srcs

SRCS			:=	$(SRCSDIR)/main.c

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

$(NAME)			:	compile_libs $(OBJS) 
					$(CC) -o $@ $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJS)

.PHONY			:	compile_libs
compile_libs	:	
					make -C minilibx_macos/
					make -C libft/

$(OBJS)			: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean			:
					rm -f $(OBJS)
					make clean -C minilibx_macos/
					make clean -C libft/

fclean			:	clean
					rm -f $(NAME)
					make fclean -C libft/

re				:	fclean all
