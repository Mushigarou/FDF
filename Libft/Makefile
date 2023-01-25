# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 20:08:38 by mfouadi           #+#    #+#              #
#    Updated: 2023/01/21 02:27:24 by mfouadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------------------------------------------------------------
# Source Files
#----------------------------------------------------------------------------------------------
SRC = 	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlcpy.c	\
		ft_isalpha.c	ft_isdigit.c	ft_strlcat.c	ft_strlen.c		\
		ft_strncmp.c	ft_toupper.c	ft_tolower.c	ft_strnstr.c	\
		ft_strchr.c		ft_strrchr.c	ft_memset.c		ft_bzero.c		\
		ft_memchr.c		ft_memcmp.c		ft_memmove.c	ft_atoi.c		\
		ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	\
		ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	\
		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c  ft_split.c		\
		ft_calloc.c 	ft_memcpy.c		ft_lstnew.c		ft_lstadd_front.c \
		ft_lstsize.c	ft_lstlast.c	ft_lstiter.c	ft_lstdelone.c	\
		ft_lstclear.c	ft_lstmap.c	 ft_lstadd_back.c

#----------------------------------------------------------------------------------------------
# Adding the object directory path as a prefix to the source files
#----------------------------------------------------------------------------------------------
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

#----------------------------------------------------------------------------------------------
# Variables
#----------------------------------------------------------------------------------------------
NAME = libft.a

CFLAGS = -Werror -Wextra -Wall

HEADER = libft.h

OBJ_DIR = obj

RM = /bin/rm -rf

TOTAL_FILES = $(shell echo `ls *.c | wc -l`)

FILES_COMPILED = 0
#----------------------------------------------------------------------------------------------
# Terminal ANSI colors
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
# Main dependencies
#----------------------------------------------------------------------------------------------

# tput cvvis (cursor visible): make the cursor of the terminal visible.
# tput civis (cursor invisible): make the cursor of the terminal invisible
# tput el : clear current line. Used to provide a cleaner display of the makefile output.

# $(eval ...) and $(shell ...) are both used to execute commands in shell and
#		and capture their output

# $(eval ...) is used to dynamically generate makefile rules.
#		 - Output of the command is interpreted as makefile code
#		 - Generated code is added to the Makefile and executed when the makefile run

# $(shell ...) is used to capture the value of the output of shell and stores it 
#			in a make variable
#		- i.e. $(shell TEST = $(echo "hello"))

# bc : is a command-line calculator utility. it reads from stdin.
#		- Evaluate the mathematical expression and return the result.
#		- Arithmetic, trigonemetry, square root, mathematical operations...
#		- echo "5 + 7" | bc

# tr : copies the standard input to the standard output with 
#		substitution or deletion of selected characters.

# \r : Move the cursor to the beginning of the line, and prints the updated output 
#		and the cursor will not move to the next line.
#		- doesn't work if you redirect the output to a file or a pipe.
#		- it's also possible to pipe the output to the cat command, so the cursor doesn't go to the next line

all : $(NAME)
	@ tput cvvis

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	tput el
	ar rcs $(NAME) $(OBJECTS)
	printf "♠"${HBLU}" [%+32s] \n"${NC} "Libft is ready to be linked"

$(OBJ_DIR)/%.o : %.c $(HEADER)
	$(eval FILES_COMPILED = $(shell echo "$(FILES_COMPILED) + 1" | bc ))
	@ printf ${HWHT}"  Compiling ▻"${HBLU}" [%-20s] "${HWHT} $(notdir $@)
	@ echo "$(FILES_COMPILED) * 100 / $(TOTAL_FILES)" | bc | tr -d '\n'
	@ printf "%% \r"${NC}
	@ $(CC) $(CFLAGS) -c $< -o $@ || stty -echo

$(OBJ_DIR) :
	@ mkdir obj

#----------------------------------------------------------------------------------------------
# Deleting object files
#----------------------------------------------------------------------------------------------
clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#----------------------------------------------------------------------------------------------
# Special Built-in Target Names
#----------------------------------------------------------------------------------------------
.Phony : all clean fclean re
.SILENT : bonus $(NAME) clean fclean re
.DEFAULT_GOAL := all