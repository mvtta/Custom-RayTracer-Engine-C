# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:03:46 by user              #+#    #+#              #
#    Updated: 2022/05/17 09:26:39 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|	libbim: lib for basic input management
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

CONFIG = libbim_config.mk
include $(CONFIG)
	
${EXEC}: $(_OBJ)
	mkdir -p ${BROOT}
	mkdir -p ${OROOT}
	@printf "\e[31m[dirs]\e[0m\n"
	$(AR) rcs $@ $^
	ranlib $@
	@printf "\e[31m[MADE LIB]\e[0m\n"
	-@mv $@ ${BROOT}
	-@mv $^ ${OROOT}
	@printf "\e[31m[MOVED FOLDERS]\e[0m\n"

all: ${EXEC}

$(_OBJ):$(SRCS)
	@printf "\e[31m[ENTERED OBJ RULE]\e[0m\n"
	$(CC) $(CFLAGS) $(SRC) -c -I${IROOT} $<
	@printf "\e[31m[MADE OBJSs]\e[0m\n"
	#$(CC) -c $(CFLAGS) -I$(_DEPS) $< -o $@
clean :
	@rm -f $(EXEC)
	@printf "\e[31mclean done ✔️\e[0m\n"

fclean : clean
	@rm -rf $(BROOT)
	@rm -rf $(OROOT)
	@printf "\e[32mbin directory clean 👾\e[0m\n"
	@printf "\e[31mfsuper clean done ✔️\e[0m\n"

re : fclean all

.PHONY: all clean fclean re


# ********************************************************************************
# * for building user libraries of all sorts.
# * the present version does:
# 	~ has .o as pre-requisite
# 	~ targets a .a static library file
# 	~ creates a ./obj directory for such .o files
# 	~ moves .o files into ./obj directory
# 	~ creates a ./bin directory for such .a files
# 	~ archives .a && .o
# 	~ moves .a files into ./bin directory# 
# * and includes:
# 	~ a pattern rule for %.o:%.c
# 	~ a clean rule
# 	~ a re make rule
# 	~ phony rule# 
# * usage sugestion:
# 	~ use the libconfig.mk file to edit/add your variables
# 	~ remeber in case of new variables on config.mk to use them in Make ^^
# 	~ use echo or printf do debug if strugling
# 	~ don't forget to include $(CONFIG) ^^
# 	~ $@ this means target as in :
# *								${TARGET}: $(_OBJ)
# 	~ $^ this means obj    as in :
# *								${TARGET}: $(_OBJ)
# * Sugestions are welcome, 
# * Enjoy (vendettta Mlib0.0)
# ********************************************************************************