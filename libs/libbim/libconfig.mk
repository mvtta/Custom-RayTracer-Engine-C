# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
# *|G|e|n|e|r|i|c| |M|a|k|e|f|i|l|e|
# *+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+

TARGET		= libbim.a
IDIR		= includes/
ODIR 		= obj/
BUILDDIR	= bin/
ADIR 		= bin/
LBIR 		= ../libft
SDIR 		= srcs/filetype_is_valid.c
LIB 		= -lft
CC       	= gcc
AR       	= ar
ARFLAGS  	= rcs
_DEPS 		= includes/bimlib.h
_LIBDEP		= ../libft/includes/libft.h
_DEPS 		= includes/bimlib.h
_OBJ 		= filetype_is_valid.o

# ********************************************************************************
# * for building user libraries of all sorts.
# * use config file with caution 
# * Sugestions are welcome, 
# * Enjoy (vendettta Mlib0.0 / Mlib0.0.mk)
# ********************************************************************************