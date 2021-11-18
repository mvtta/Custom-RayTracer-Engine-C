# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 12:36:54 by mvaldeta          #+#    #+#              #
#    Updated: 2021/11/18 16:12:24 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# Makefile
################################################################################

# Makefile by mvaldeta (tired of !understanting makefiles)
# Version 0.0

################################################################################
# $@ evaluates to all
# $< evaluates to server
# $^ evaluates to server & client
#
# Automatic variables
#
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. 
#
# The -c flag generates the .o file; see man gcc for a more detailed explanation. 
# The -o specifies the output file to create.
# make -p for makefile database
################################################################################

EXEC = ./minirt

HEADERS = includes/

SRC_EXEC = ${wildcard srcs/*.c}

LIBFT = libft/bin/libft.a

SRC_LIBFT = libft/

BIN_ROOT = bin/
OBJ_ROOT	= obj/


################################################################
# compiler + flags minirt
################################################################

CC = gcc

CFLAGS = -g  -Imlx #-Werror -Wall -Wextra

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit 

O_EXEC =  $(SRC_MAIN:%.c=%.o)

all : $(EXEC)

$(EXEC) : ${LIBFT} $(O_EXEC)
	${AT} mkdir -p ${BIN_ROOT}
	${AT} $(CC) $(CFLAGS) -I $(HEADERS) ${LIBFT} $(SRC_EXEC) $(O_EXEC) -o ${BIN_ROOT}$@
	@printf "\e[32m${EXEC}built🎆\e[0m\n"

${LIBFT} :
					make -C ${SRC_LIBFT}
					@printf "\e[32mcreating libft🎆\e[0m\n"

clean :
	$(RM) $(O_FILES)
	@printf "\e[31mclean done ✔️\e[0m\n"

fclean : clean
	$(RM) $(EXEC) $(LIBFT) ${BIN_ROOT}
	@printf "\e[31mfsuper clean done ✔️\e[0m\n"

re : fclean all

.PHONY: all clean fclean re