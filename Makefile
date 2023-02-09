# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 05:59:30 by mfouadi           #+#    #+#              #
#    Updated: 2023/02/09 06:18:53 by mfouadi          ###   ########.fr        #
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

TOTAL_FILES = $(shell echo `cd src && ls *.c | wc -l`)

FILES_COMPILED = 0

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

all :art libft_archive $(NAME) fdf

$(NAME) : dir $(OBJ_PATH)
	@ $(CC) $(OBJ_PATH) $(ARCHIVE) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I include
# @ printf ${HYEL}"♠"${HWHT}" Executable...  ▻"${HYEL}" [%-20s]\n\n"${NC} $(notdir $@)

libft_archive :
	@ make -C Libft

obj/%.o : src/%.c $(HEADER)
	@ $(CC) $(CFLAGS) $< -o $@ ${INCLUDE}
# $(eval FILES_COMPILED = $(shell echo "$(FILES_COMPILED) + 1" | bc))
# @ printf ${HYEL}"♠"${HWHT}" Compiled  ▻"${HYEL}" [%-20s]"${HWHT} $(notdir $@)
# @ echo "$(FILES_COMPILED) * 100 / ${TOTAL_FILES}" | bc | tr -d '\n'
# @ printf "%% \r"${NC}

dir : 
	mkdir -p bin obj

clean :
	make clean -C Libft
	$(RM) $(OBJ) $(LIBFT_OBJ) bin obj a.out */a.out

fclean : clean
	make fclean -C Libft
	$(RM) $(NAME)

re : fclean all

#----------------------------------------------------------------------------------------------
# Decoration
#----------------------------------------------------------------------------------------------

art:
	@printf ${HWHT}"\n           /\\ .-\"\"\"-. /\\ \n"
	@printf "           \\ \`\"\`'v'\`\"\` / \n"
	@printf "           { .=.   .=. } \n"
	@printf "           {( "${HYEL}"O"${NC}${HWHT}" ) ( "${HYEL}"O"${NC}${HWHT}" )} \n"
	@printf "            .\\'=' V '='/. 		    *******************\\n"
	@printf "          /.'\`-'-'-'-\`'.\\ **************** | Hang Tight! Amigo |\n"
	@printf "         |/   ^  ~  ^   \\| 		    *******************\\n"
	@printf "         \\|    ^   ^    |/ \n"
	@printf "          \\\\\\           // \n"
	@printf "           \\\\\\ _     _ // \n"
	@printf "      "${HYEL}" -----"${HWHT}"'(|)"${HYEL}"---"${HWHT}"(|)'"${HYEL}"----- \n"
	@printf "       ------"${HWHT}","${HYEL}"-------"${HWHT}","${HYEL}"------ \n"${HWHT}
	@printf "            / .' : '. \\ \n"
	@printf "           '-'._.-._.'-' \n\n"
	@printf ${NC}

fdf :
	@printf ${HYEL}"          _____                    _____                    _____\n"
	@printf "         /\    \                  /\    \                  /\    \ \n"
	@printf "        /::\    \                /::\    \                /::\    \ \n"
	@printf "       /::::\    \              /::::\    \              /::::\    \ \n"
	@printf "      /::::::\    \            /::::::\    \            /::::::\    \ \n"
	@printf "     /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \ \n"
	@printf "    /:::/__\:::\    \        /:::/  \:::\    \        /:::/__\:::\    \ \n"
	@printf "   /::::\   \:::\    \      /:::/    \:::\    \      /::::\   \:::\    \ \n"
	@printf "  /::::::\   \:::\    \    /:::/    / \:::\    \    /::::::\   \:::\    \ \n"
	@printf " /:::/\:::\   \:::\    \  /:::/    /   \:::\ ___\  /:::/\:::\   \:::\    \ \n"
	@printf "/:::/  \:::\   \:::\____\/:::/____/     \:::|    |/:::/  \:::\   \:::\____\ \n"
	@printf "\::/    \:::\   \::/    /\:::\    \     /:::|____|\::/    \:::\   \::/    / \n"
	@printf " \/____/ \:::\   \/____/  \:::\    \   /:::/    /  \/____/ \:::\   \/____/ \n"
	@printf "          \:::\    \       \:::\    \ /:::/    /            \:::\    \ \n"
	@printf "           \:::\____\       \:::\    /:::/    /              \:::\____\ \n"
	@printf "            \::/    /        \:::\  /:::/    /                \::/    / \n"
	@printf "             \/____/          \:::\/:::/    /                  \/____/ \n"
	@printf "                               \::::::/    /                                \n"
	@printf "                                \::::/    /                                 \n"
	@printf "                                 \::/____/                                  \n"
	@printf "                                  ~~                            \n"${NC}
#----------------------------------------------------------------------------------------------
# Built-in Targets
#----------------------------------------------------------------------------------------------
.PHONY : re fclean clean dir
.SILENT : clean fclean $(NAME) dir
.DEFAULT_GOAL : all
