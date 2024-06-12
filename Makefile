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

# HEADER_FILES	=	fractol.h parsing.h
# HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))

# LIB				=	

# #--- COMMAND VARIABLES ---#

# CC		=	clang
# CFLAGS 	=	-Wall -Wextra -Werror -g #-fsanitize=address
# MK		=	mkdir -p
# RM		=	rm -rf

# #--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

# INCDIR	=	inc
# LIBDIR	=	lib
# SRCDIR	=	src
# BINDIR	=	bin

# #--- SOURCES ---#

# SRCS	=	main.c parsing/parsing.c
# SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
# BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))

# #--- RULES ---#

# $(BINDIR)/%.o	: $(SRCDIR)/%.c $(HEADERS)
# 	@$(MK) $(@D)
# 	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# all			: ${NAME}

# ${NAME}		: ${BIN}
# 	@$(CC) ${CFLAGS} ${BIN} -o ${NAME}
# 	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"

# makelib		:
# 	make

# clean		:
# 	@${RM} ${BINDIR}
# 	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"

# fclean		: clean
# 	@${RM} ${NAME}
# 	@echo "${RED}Executable successfully removed 🗑${DEFAULT}"

# re	 		: fclean all

# #--- PHONY ---#

# .PHONY	 	: all clean fclean re 



#-------version mike----------#

#--- PROGRAM NAME ---#

NAME	=	fractol

#--- COLORS ---#

RED			= \033[1;31m
GREEN		= \033[1;32m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
DARKGRAY	= \033[1;30m
DEFAULT		= \033[0m

#--- LIBRARIES AND HEADERS ---#

HEADER_FILES	=	fractol.h parsing.h
HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))

LIBFT_DIR		=	${LIBDIR}/libft # variable que contiene el path hacia la libft
BUILDLIB		=	make -C ${LIBFT_DIR}
CLEANLIB		=	make clean -C ${LIBFT_DIR}
MLX_DIR			=	-framework Cocoa -framework OpenGL -framework IOKit lib/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/mabril/.brew/lib"

#LIBFT_NAME		=	libft.a
#LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft -Wall -Wextra -Werror -g #-fsanitize=address


#--- COMMAND VARIABLES ---#

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -g #-fsanitize=address
MK		=	mkdir -p
RM		=	rm -rf

#--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

INCDIR	=	inc
LIBDIR	=	lib
SRCDIR	=	src
BINDIR	=	bin

#--- SOURCES ---#

SRCS	=	main.c parsing/parsing.c
SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))

#--- RULES ---#

$(BINDIR)/%.o	: $(SRCDIR)/%.c $(HEADERS)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@

# # Regla para construir la libft ----------------------------------------------nuevo
# $(LIBFT_NAME):
# 	@$(MAKE) -C $(LIBFT_DIR)


all			: ${NAME} 

${NAME}		: ${BIN}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} $(LIBFT_FLAGS) $(MLX_DIR) ${BIN} -o ${NAME}		#-----------------------nuevo------------//#
	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"

# makelib		:
# 	make

clean		:
	@${RM} ${BINDIR}
	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"
	

fclean		: clean
	@${CLEANLIB}
	@${RM} ${NAME}
	@echo "${RED}Executable successfully removed 🗑${DEFAULT}"

re	 		: fclean all

#--- PHONY ---#

.PHONY	 	: all clean fclean re 