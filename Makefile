# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 12:35:58 by mabril            #+#    #+#              #
#    Updated: 2024/08/20 20:46:55 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- PROGRAM NAME ---#

NAME	=	fractol
NAME_BONUS = fractol_bonus

#--- COLORS ---#

RED			= \033[1;31m
GREEN		= \033[1;32m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
DARKGRAY	= \033[1;30m
DEFAULT		= \033[0m
#--- LIBRARIES AND HEADERS ---#

HEADER_FILES	=	fractol.h
HEADER_FILES_B	=	fractol_bonus.h
HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))
HEADERS_B			=	$(addprefix $(INCDIR)/, $(HEADER_FILES_B))

LIBFT_DIR		=	${LIBDIR}/libft # variable que contiene el path hacia la libft
BUILDLIB		=	make -C ${LIBFT_DIR}
CLEANLIB		=	make fclean -C ${LIBFT_DIR}
MLX_DIR			=	-framework Cocoa -framework OpenGL -framework IOKit lib/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/mabril/.brew/lib"
# MLX_DIR			=   lib/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

#--- COMMAND VARIABLES ---#

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -g #-fsanitize=address
MK		=	mkdir -p
RM		=	rm -rf

#--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

INCDIR	=	inc
LIBDIR	=	lib
SRCDIR	=	src
SRCDIRBONUS = src_bonus
BINDIR	=	bin
BINDIRBONUS	=	bin_bonus

#--- SOURCES ---#
  
SRCS	=	main.c utils.c init.c render.c math.c hook.c
SRCS_BONUS	=	main_bonus.c utils_bonus.c init_bonus.c render_bonus.c math_bonus.c hook_bonus.c
SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
SRC_BONUS		=	$(addprefix $(SRCDIRBONUS)/, $(SRCS_BONUS))
BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))
BIN_BONUS     =	$(patsubst $(SRCDIRBONUS)/%.c,$(BINDIRBONUS)/%.o,$(SRC_BONUS))

#--- RULES ---#
$(BINDIR_BONUS)/%.o	: $(SRCDIRBONUS)/%.c $(HEADERS_B)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(BINDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@

	

all			: ${NAME} 
	
${NAME}		: ${BIN}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} ${BIN} -o ${NAME} -L${LIBFT_DIR} -lft $(MLX_DIR) #-----------------------nuevo------------//#
	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"


${NAME_BONUS}	: ${BIN_BONUS}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} ${BIN_BONUS} -o ${NAME_BONUS} -L${LIBFT_DIR} -lft $(MLX_DIR) #-----------------------nuevo------------//#
	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"
	
	
clean		:
	@${RM} ${BINDIR}
	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"
		

fclean		: clean
	@${CLEANLIB}
	@${RM} ${NAME} ${NAME_BONUS} ${LIBFT_NAME}
	@echo "${RED}Executable successfully removed 🗑${DEFAULT}"

re	 		: fclean all

bonus: $(NAME_BONUS)

#--- PHONY ---#

.PHONY	 	: all clean fclean re 