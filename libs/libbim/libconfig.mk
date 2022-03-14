# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

EXEC		= libbim.a
IROOT		= includes/
L1ROOT		= ../libft
_LIBDEP		= ../libft/includes/libft.h
SRC 		= ${wildcard srcs/*.c}
OBJ 		= ${patsubst %.c,%.o,${SRC:%.c}}
OROOT 		= obj/
BROOT		= bin/
_L1			= libft.a
_OBJ 		= filetype_is_valid.o
_DEPS 		= includes/bimlib.h

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