# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:40:00 by tmaillar          #+#    #+#              #
#    Updated: 2023/05/10 07:58:18 by tmaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for building the libft library

# Output library name
NAME = libft.a

# Compiler and flags
CC			:=  cc
CFLAGS 		:= -Wall -Wextra -Werror -fPIE
CPPFLAGS 	+= -MMD -MP -MF $(@:.o=.d)

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

# Source files
GARBAGE_SRC := \
    ft_gc_addb.c \
    ft_gc_addf.c \
    ft_gc_clear.c \
    ft_gc_last.c \
    ft_gc_new.c \
    ft_memcheck.c
GARBAGE_DIR := $(addprefix $(SRC_DIR)/,garbage)
GARBAGE_OBJ := $(addprefix $(OBJ_DIR)//garbage/, $(GARBAGE_SRC:.c=.o))

GNL_SRC := \
    get_next_line.c \
    get_next_line_utils.c
GNL_DIR := $(addprefix $(SRC_DIR)/,gnl)
GNL_OBJ := $(addprefix $(OBJ_DIR)/gnl/, $(GNL_SRC:.c=.o))

LST_SRC := \
    ft_lstadd_back.c \
    ft_lstadd_front.c \
    ft_lstlast.c \
    ft_lstnew.c \
    ft_lstsize.c
LST_DIR := $(addprefix $(SRC_DIR)/,lst)
LST_OBJ := $(addprefix $(OBJ_DIR)/lst/, $(LST_SRC:.c=.o))

MEM_SRC := \
    ft_bzero.c \
    ft_calloc.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c
MEM_DIR := $(addprefix $(SRC_DIR)/,mem)
MEM_OBJ := $(addprefix $(OBJ_DIR)/mem/, $(MEM_SRC:.c=.o))

PRINTF_SRC := \
	ft_check.c \
    ft_convert.c \
    ft_printf.c \
    ft_putnbr_p.c \
    ft_putchar_p.c \
    ft_putstr_p.c \
	ft_put_memory_adress.c 
PRINTF_DIR := $(addprefix $(SRC_DIR)/,printf)
PRINTF_OBJ := $(addprefix $(OBJ_DIR)/printf/, $(PRINTF_SRC:.c=.o))

PUT_SRC := \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_putstr_fd.c 
PUT_DIR := $(addprefix $(SRC_DIR)/,put)
PUT_OBJ := $(addprefix $(OBJ_DIR)/put/, $(PUT_SRC:.c=.o))

STR_SRC := \
    ft_split.c \
    ft_strchr.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c 
STR_DIR := $(addprefix $(SRC_DIR)/,str)
STR_OBJ := $(addprefix $(OBJ_DIR)/str/, $(STR_SRC:.c=.o))

UTILS_SRC := \
	ft_atoi.c \
	ft_itoa.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_swap.c \
    ft_tolower.c \
	ft_toupper.c
UTILS_DIR := $(addprefix $(SRC_DIR)/,utils)
UTILS_OBJ := $(addprefix $(OBJ_DIR)/utils/, $(UTILS_SRC:.c=.o))

# Combine all source files and object files
SRC := $(GARBAGE_SRC) $(GNL_SRC) $(LST_SRC) $(MEM_SRC) \
	    $(PRINTF_SRC) $(PUT_SRC) $(STR_SRC) $(UTILS_SRC)
OBJ := $(GARBAGE_OBJ) $(GNL_OBJ) $(LST_OBJ) $(MEM_OBJ) \
	    $(PRINTF_OBJ) $(PUT_OBJ) $(STR_OBJ) $(UTILS_OBJ)

# Default target
all: $(NAME)

# Rules to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $@ $^

# Clean up object files
clean:
	rm -rf $(OBJ_DIR)

# Remove object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Release target: Builds an optimized release version of the library
release: CFLAGS += -O2
release: $(NAME)

# Debug Mode Configuration
DEBUG	:= 0

ifeq ($(DEBUG), 1)
    CFLAGS += -g3
endif

# Phony targets
.PHONY: all clean debug fclean re release

# Include .d files (dependency files)
-include $(OBJ:.o=.d)