# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 12:36:54 by mvaldeta          #+#    #+#              #
#    Updated: 2021/12/03 09:55:40 by user             ###   ########.fr        #
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

EXEC 		= ./minirt
HEADERS 	= includes/
SRC_EXEC 	= ${wildcard srcs/*.c}
LIBFT 		= libs/libft/bin/libft.a
SRC_LIBFT 	= libs/libft/
BIN_ROOT 	= bin/
OBJ_ROOT	= obj/


################################################################
# compiler + flags minirt
################################################################

CC = gcc

#-fsanitize=address

CFLAGS = -g -Imlx -Werror -Wall -Wextra

MLX_DIR = libs/minilibx_opengl_20191021

MLX_FLAGS = -L ./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 

MLX_FILE = $(MLX_DIR)libmlx.a

O_EXEC =  $(SRC_MAIN:%.c=%.o)

all : $(EXEC)

$(EXEC) : ${LIBFT} $(MLX_FILE) $(O_EXEC)
	mkdir -p ${BIN_ROOT}
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(HEADERS) ${LIBFT} $(SRC_EXEC) $(O_EXEC) -o ${BIN_ROOT}$@
	@printf "\e[32m${EXEC}built🎆\e[0m\n"

${LIBFT} :
					make -C ${SRC_LIBFT}
					@printf "\e[32mcreating libft🎆\e[0m\n"

${MLX_FILE} : 
					@make -C $(MLX_DIR) 
					@printf "\e[32mcreating MLX🎆\e[0m\n"

clean :
	@rm -f $(O_EXEC)
	@printf "\e[31mclean done ✔️\e[0m\n"

fclean : clean
	@rm -rf $(BIN_ROOT)
	@printf "\e[32mbin directory clean 👾\e[0m\n"
	@rm -f $(EXEC) $(LIBFT)
	@printf "\e[32mlibft clean 👾\e[0m\n"
	@printf "\e[31mfsuper clean done ✔️\e[0m\n"

re : fclean all

.PHONY: all clean fclean re