# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 19:44:38 by user              #+#    #+#              #
#    Updated: 2022/03/10 19:47:11 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

CONFIG = rtconfig.mk
include $(CONFIG)

${EXEC}: ${LIBS} $(OBJ)	
	mkdir -p ${BROOT}
	$(CC) $(CFLAGS) ${LINKFLAGS} -I${IROOT} ${SRC} -o ${OBJ} ${EXEC}
	mv $@ $(BROOT)
	printf "\e[31m[ALL]\e[0m\n"
	printf "\e[31m[OUT]\e[0m\n"

${LIBS}:
	printf "\e[31m[BUILD LIBS]\e[0m\n"
	make -C libs/libft
	make -C libs/libbim
	make -C libs/minilibx_ogl
	printf "\e[31m[DONE LIBS]\e[0m\n"

$(OBJ):
	mkdir -p ${OROOT}

all : ${EXEC}

.o:%.c
	$(CC) $(CFLAGS) $(OBJ) -c $<

clean :
	@rm -f $(O_EXEC)
	@printf "\e[31mclean done ✔️\e[0m\n"

fclean : clean
	@rm -rf $(BROOT)
	@rm -rf $(OROOT)
	@printf "\e[32mbin directory clean 👾\e[0m\n"
	@rm -f $(EXEC) $(LIBFT)
	@printf "\e[32mlibft clean 👾\e[0m\n"
	@printf "\e[31mfsuper clean done ✔️\e[0m\n"

re : fclean all

.PHONY: all clean fclean re
