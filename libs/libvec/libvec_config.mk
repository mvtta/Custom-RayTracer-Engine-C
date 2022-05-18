# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

EXEC		= libvec.a
IROOT		= includes/
L1ROOT		= ../libft
_LIBDEP		= ../libft/includes/libft.h
SROOT		= srcs


SRC 		:= $(shell find $(SROOT) -name '*.c')
OBJ 		= ${patsubst %.c,%.o,${SRC:%.c}}
OROOT 		= obj/
BROOT		= bin/

_L1			= libvec.a
_OBJ		= cross_p.o \
						dot_p.o\
						normalize.o\
						raydir.o\
						rayorigin.o\
						v_3.o\
						v_add.o\
						v_angle2.o\
						v_from2p.o\
						v_len.o\
						v_lensqr.o\
						v_mag.o\
						v_mult.o\
						v_scale.o\
						v_sqr.o\
						v_sub.o


_DEPS 		= includes/libvec.h
				

CC       	= gcc
LINK_L1		= -L${L1ROOT}/bin -lft
LINKFLAGS	= ${LINK_L1}
CFLAGS		= -g -fsanitize=address -Werror -Wall -Wextra
AR       	= ar
ARFLAGS  	= rcs

# ********************************************************************************
# * for building user libraries of all sorts.
# * use config file with caution 
# * Sugestions are welcome, 
# * Enjoy (vendettta Mlib0.0 / Mlib0.0.mk)
# ********************************************************************************