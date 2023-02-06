# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 05:59:30 by mfouadi           #+#    #+#              #
#    Updated: 2023/02/06 22:48:36 by mfouadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------------------------------------------------------------
# Variables
#----------------------------------------------------------------------------------------------

NAME = bin/fdf

CC = cc

CFLAGS = -Wall -Werror -Wextra -Imlx -c

SRC = draw.c main.c get_map.c utils.c init.c

OBJ = $(SRC:.c=.o)

OBJ_PATH = $(addprefix obj/, $(OBJ))

ARCHIVE = Libft/libft.a

HEADER = include/fdf.h

INCLUDE = -I include -I Libft

RM = rm -rf

LIBFT_OBJ = Libft/obj

#----------------------------------------------------------------------------------------------
# Colors ANSI Terminal
#----------------------------------------------------------------------------------------------

HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC ='\033[0m'

#----------------------------------------------------------------------------------------------
# Complilation
#----------------------------------------------------------------------------------------------

# -L : Specify the directory where the linker should look for libraries
# -l : Specify the library to link against
# -I : tells the compliler to look for include files (headers)
#		in a specific directory. (#include in source code)

# OpenGL is a cross-platform graphics API (Application Programming Interface)
# 	3D applications and games
# AppKit provides a set of tools and interfaces for creating graphical user
# 	interfaces, handling events, managing windows and views, and other common tasks

all : $(NAME)

$(NAME) : dir $(OBJ_PATH)
	make -C Libft
	@ $(CC) $(OBJ_PATH) $(ARCHIVE) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I include
	@ printf ${HWHT}"♠ Running Executable...  ▻"${HBLU}" [%-20s]\n"${NC} $(notdir $@)

obj/%.o : src/%.c $(HEADER)
	@ $(CC) $(CFLAGS) $< -o $@ ${INCLUDE}
	@ printf ${HWHT}"♠ Compiled  ▻"${HBLU}" [%-20s]\n"${NC} $(notdir $@)

dir : 
	mkdir -p bin obj

clean :
	make clean -C Libft
	$(RM) $(OBJ) $(LIBFT_OBJ) bin obj a.out */a.out

fclean : clean
	make fclean -C Libft
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean dir
.SILENT : clean fclean $(NAME) dir
