# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:03:46 by user              #+#    #+#              #
#    Updated: 2022/03/10 19:46:57 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

CONFIG = libconfig.mk
include $(CONFIG)

${TARGET}: $(_OBJ)
	mkdir -p ${ADIR}
	$(AR) rcs $@ ${ODIR}$(_OBJ)
	@mv $@ ${ADIR}

$(_OBJ):
	mkdir -p ${ODIR}
	@mv $^ $(ODIR)

all: ${TARGET}

%.o:%.c
	$(CC) $(CFLAGS) $(_OBJ) -c $<

clean:
	rm -rf $(ODIR) $(BUILDDIR) 

.PHONY: clean

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