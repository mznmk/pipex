# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 23:19:36 by mmizuno           #+#    #+#              #
#    Updated: 2022/04/01 21:10:06 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= pipex

PIPEX_INC_DIR		= ./incs/
PIPEX_SRC_DIR		= ./srcs/

MANDA_NAME			= pipex
MANDA_SRC_NAME		= file_io.c \
					  pipex.c \
					  main_manda.c
MANDA_SRCS			= $(addprefix $(PIPEX_SRC_DIR), $(MANDA_SRC_NAME))
MANDA_OBJS			= $(MANDA_SRCS:.c=.o)					  

BONUS_NAME			= pipex
BONUS_SRC_NAME		= file_io.c \
					  pipex.c \
					  main_bonus.c
BONUS_SRCS			= $(addprefix $(PIPEX_SRC_DIR), $(BONUS_SRC_NAME))
BONUS_OBJS			= $(BONUS_SRCS:.c=.o)					  

P0_C1_NAME			= p0c1
P0_C1_SRC_NAME		= sample_pipe0_cmd1.c
P0_C1_SRCS			= $(addprefix $(PIPEX_SRC_DIR), $(P0_C1_SRC_NAME))
P0_C1_OBJS			= $(P0_C1_SRCS:.c=.o)					  

P1_C2_NAME			= p1c2
P1_C2_SRC_NAME		= sample_pipe1_cmd2.c
P1_C2_SRCS			= $(addprefix $(PIPEX_SRC_DIR), $(P1_C2_SRC_NAME))
P1_C2_OBJS			= $(P1_C2_SRCS:.c=.o)					  

P2_C3_NAME			= p2c3
P2_C3_SRC_NAME		= sample_pipe2_cmd3.c
P2_C3_SRCS			= $(addprefix $(PIPEX_SRC_DIR), $(P2_C3_SRC_NAME))
P2_C3_OBJS			= $(P2_C3_SRCS:.c=.o)					  

LIBFT_NAME			= libft.a
LIBFT_LIBNAME		= ft
LIBFT_DIR			= ./libs/libft/
LIBFT_INC_DIR		= $(LIBFT_DIR)includes/

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=leaks
INCDIR				= -I $(PIPEX_INC_DIR)
INCDIR				+= -I $(LIBFT_INC_DIR)
LIBDIR				= -L $(LIBFT_DIR)
LIBS				= -l $(LIBFT_LIBNAME)

RM					= rm -f

# ---------------------------------- color ----------------------------------- #

ESC_RESET			= \033[0m
FNT_BOLD			= \033[1m
FNT_FINE			= \033[2m
FNT_ITALIC			= \033[3m
FNT_ULINE			= \033[4m
CLR_BLACK			= \033[38;5;00m
CLR_RED				= \033[38;5;01m
CLR_GREEN			= \033[38;5;02m
CLR_YELLOW			= \033[38;5;03m
CLR_BLUE			= \033[38;5;04m
CLR_MAGENTA			= \033[38;5;05m
CLR_CYAN			= \033[38;5;06m
CLR_WHITE			= \033[38;5;07m
CLR_PINK			= \033[38;5;213m

# =============================== Make Command =============================== #

# ---------------------------------- .c.o ------------------------------------ #

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(MANDA_OBJS)
					@make $(LIBFT_NAME)
					$(CC) $(CFLAGS) $(MANDA_OBJS) $(LIBDIR) $(LIBS) -o $(MANDA_NAME)
					@echo "$(FNT_BOLD)$(CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all:				$(NAME)

# ------------------------------- $(LIBFT_NAME) ------------------------------ #

$(LIBFT_NAME):
					@cd $(LIBFT_DIR) && make

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(BONUS_OBJS)
					@make $(LIBFT_NAME)
					$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBDIR) $(LIBS) -o $(BONUS_NAME)
					@echo "$(FNT_BOLD)$(CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ------------------------------- $(P0_C1_NAME) ------------------------------ #

$(P0_C1_NAME):		$(P0_C1_OBJS)
					$(CC) $(CFLAGS) $(P0_C1_OBJS) -o $(P0_C1_NAME)
					@echo "$(FNT_BOLD)$(CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ------------------------------- $(P1_C2_NAME) ------------------------------ #

$(P1_C2_NAME):		$(P1_C2_OBJS)
					$(CC) $(CFLAGS) $(P1_C2_OBJS) -o $(P1_C2_NAME)
					@echo "$(FNT_BOLD)$(CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ------------------------------- $(P2_C3_NAME) ------------------------------ #

$(P2_C3_NAME):		$(P2_C3_OBJS)
					$(CC) $(CFLAGS) $(P2_C3_OBJS) -o $(P2_C3_NAME)
					@echo "$(FNT_BOLD)$(CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ---------------------------------- clean ----------------------------------- #

clean:
					@cd $(LIBFT_DIR) && make clean
					$(RM) $(MANDA_OBJS) $(BONUS_OBJS) $(P0_C1_OBJS) $(P1_C2_OBJS) $(P2_C3_OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					@cd $(LIBFT_DIR) && make fclean
					$(RM) $(MANDA_NAME) $(BONUS_NAME) $(P0_C1_NAME) $(P1_C2_NAME) $(P2_C3_NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all bonus clean fclean re
