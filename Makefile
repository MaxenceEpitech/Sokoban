##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Sat May 13 15:54:39 2017 fourrier maxence
##

DEBUG		=	no

NAME		= 	my_sokoban

CC		= 	gcc

ECHO		=	echo

RM		= 	rm -f

SRCS_DIR	= 	./src/

SRCS		=	$(SRCS_DIR)main.c			\
			$(SRCS_DIR)tools.c			\
			$(SRCS_DIR)create_list.c		\
			$(SRCS_DIR)my_tab.c			\
			$(SRCS_DIR)check_error.c		\
			$(SRCS_DIR)game.c			\
			$(SRCS_DIR)create_tab.c			\
			$(SRCS_DIR)game_lost.c			\
			$(SRCS_DIR)info_tab.c			\
			$(SRCS_DIR)move_player.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-Wall -Wextra -Werror -I./include

LDFLAGS		+=	-L./lib/my -lmy -lncurses

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-g3
endif

all		:	$(NAME)

$(NAME)		: 	$(OBJS)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean		:
			make clean -C ./lib/my
			$(RM) $(OBJS)

fclean		:	clean
			make fclean -C ./lib/my
			$(RM) $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re

