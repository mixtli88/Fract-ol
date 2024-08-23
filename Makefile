# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 12:35:58 by mabril            #+#    #+#              #
#    Updated: 2024/08/22 18:25:21 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #--- PROGRAM NAME ---#

# NAME	=	fractol

# #--- COLORS ---#

# RED			= \033[1;31m
# GREEN		= \033[1;32m
# BLUE		= \033[1;34m
# YELLOW		= \033[1;33m
# DARKGRAY	= \033[1;30m
# DEFAULT		= \033[0m
# #--- LIBRARIES AND HEADERS ---#

# HEADER_FILES	=	fractol.h
# HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))

# LIBFT_DIR		=	${LIBDIR}/libft # variable que contiene el path hacia la libft
# BUILDLIB		=	make -C ${LIBFT_DIR}
# CLEANLIB		=	make fclean -C ${LIBFT_DIR}
# MLX_DIR			=	-framework Cocoa -framework OpenGL -framework IOKit lib/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/mabril/.brew/lib"
# # MLX_DIR			=   lib/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# #--- COMMAND VARIABLES ---#

# CC		=	gcc
# CFLAGS 	=	-Wall -Wextra -Werror -g #-fsanitize=address
# MK		=	mkdir -p
# RM		=	rm -rf

# #--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

# INCDIR	=	inc
# LIBDIR	=	lib
# SRCDIR	=	src
# BINDIR	=	bin

# #--- SOURCES ---#
  
# SRCS	=	main.c utils.c init.c render.c math.c hook.c
# SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
# BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))


# #--- RULES ---#
	
# $(BINDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
# 	@$(MK) $(@D)
# 	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
# 	@$(CC) $(CFLAGS) -c $< -o $@

	

# all			: ${NAME} 
	
# ${NAME}		: ${BIN}
# 	@${BUILDLIB}
# 	@$(CC) ${CFLAGS} ${BIN} -o ${NAME} -L${LIBFT_DIR} -lft $(MLX_DIR) #-----------------------nuevo------------//#
# 	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"
	
# clean		:
# 	@${RM} ${BINDIR}
# 	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"
		

# fclean		: clean
# 	@${CLEANLIB}
# 	@${RM} ${NAME} ${LIBFT_NAME}
# 	@echo "${RED}Executable successfully removed 🗑${DEFAULT}"

# re	 		: fclean all


# #--- PHONY ---#

# .PHONY	 	: all clean fclean re 

NAME	=	fractol
BONUS_NAME = fractol_bonus

#--- LIBRARIES AND HEADERS ---#

HEADER_FILES	=	fractol.h
BONUS_HEADER_FILES = fractol_bonus.h
HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))
BONUS_HEADERS	=	$(addprefix $(INCDIR)/, $(BONUS_HEADER_FILES))

LIBFT_DIR		=	${LIBDIR}/libft
BUILDLIB		=	make -C ${LIBFT_DIR}
CLEANLIB		=	make fclean -C ${LIBFT_DIR}
MLX_DIR			=	-framework Cocoa -framework OpenGL -framework IOKit lib/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/mabril/.brew/lib"
# MLX_DIR			=   lib/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm # mv

#--- COMMAND VARIABLES ---#

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -g
MK		=	mkdir -p
RM		=	rm -rf

#--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

INCDIR	=	inc
LIBDIR	=	lib
SRCDIR	=	src
BONUS_SRCDIR = src_bonus
BINDIR	=	bin
BONUS_BINDIR = bin_bonus

#--- SOURCES ---#

SRCS	=	main.c utils.c init.c render.c math.c hook.c
BONUS_SRCS = main_bonus.c utils_bonus.c init_bonus.c render_bonus.c math_bonus.c hook_bonus.c

SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
BONUS_SRC = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCS))

BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))
BONUS_BIN = $(patsubst $(BONUS_SRCDIR)/%.c,$(BONUS_BINDIR)/%.o,$(BONUS_SRC))

#--- RULES ---#

$(BINDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_BINDIR)/%.o : $(BONUS_SRCDIR)/%.c $(BONUS_HEADERS)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling bonus: $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@

all			: ${NAME} ${BONUS_NAME}

${NAME}		: ${BIN}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} ${BIN} -o ${NAME} -L${LIBFT_DIR} -lft $(MLX_DIR)
	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"


${BONUS_NAME} : ${BONUS_BIN}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} ${BONUS_BIN} -o ${BONUS_NAME} -L${LIBFT_DIR} -lft $(MLX_DIR)
	@echo "${GREEN}${BONUS_NAME} successfully created. 🌐${DEFAULT}"

clean		:
	@${RM} ${BINDIR} ${BONUS_BINDIR}
	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"

fclean		: clean
	@${CLEANLIB}
	@${RM} ${NAME} ${BONUS_NAME} ${LIBFT_NAME}
	@echo "${RED}Executables successfully removed 🗑${DEFAULT}"

re	 		: fclean all

bonus		: ${BONUS_NAME}
#--- PHONY ---#

.PHONY	 	: all bonus clean fclean re