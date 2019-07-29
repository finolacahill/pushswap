# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcahill <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 10:30:02 by fcahill           #+#    #+#              #
#    Updated: 2019/01/18 13:44:59 by fcahill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_TWO = checker

C_SRCS = ./srcs/checker/checker.c				\
		 ./srcs/checker/get_instructions.c		\
		 ./srcs/checker/visu_draw_stacks.c		\
		 ./srcs/checker/visu.c					

P_SRCS = ./srcs/push_swap/push.c 				\
		 ./srcs/push_swap/pushswap.c			\
		 ./srcs/push_swap/quicksort.c			\
		 ./srcs/push_swap/sort_four.c			\
		 ./srcs/push_swap/sort_two_three.c		\
		 ./srcs/push_swap/sorting_functions.c	\
		 ./srcs/push_swap/trim.c					

S_SRCS = ./srcs/shared/check_build_stacks.c	\
		 ./srcs/shared/create_stacks.c		\
		 ./srcs/shared/end_functions.c		\
		 ./srcs/shared/instructions.c		\
		 ./srcs/shared/move_and_save.c		\
		 ./srcs/shared/print_stacks.c			



OBJ_C = $(C_SRCS:.c=.o)
OBJ_P = $(P_SRCS:.c=.o)
OBJ_S = $(S_SRCS:.c=.o)

INCLUDE = ./
SDL_INCLUDE = -F/Library/Frameworks -framework SDL2
CC = gcc

FLAG = -Wall -Werror -Wextra

all: check $(NAME) $(NAME_TWO) 

check:
	@make -C ./libft

$(NAME): $(OBJ_P) $(OBJ_S)
	@$(CC) $(FLAG) $(OBJ_P) $(OBJ_S) ./libft/libft.a -I $(INCLUDE) -o $(NAME)

$(NAME_TWO): $(OBJ_C) $(OBJ_S)
	@$(CC) $(FLAG) $(OBJ_C) $(OBJ_S) ./libft/libft.a -I $(INCLUDE) $(SDL_INCLUDE) -o $(NAME_TWO)

clean:
	make clean -C ./libft
	rm -f $(C_PATH) $(OBJ_C)
	rm -f $(P_PATH) $(OBJ_P)
	rm -f $(S_PATH) $(OBJ_S)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_TWO)

re: fclean all

.PHONY : all clean fclean re
