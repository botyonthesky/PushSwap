# Project name
NAME 		:= push_swap

NAME_BONUS	:= checker

# Compiler and flags
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra
CFLAGS		+= -I./include
CPPFLAGS	+= -MMD -MP -MF $(@:.o=.d)

# Directories
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_DIR_BONUS := ./src_bonus
OBJ_DIR_BONUS := ./obj_bonus

ROOT_SRC := \
	add_to.c \
	algo.c \
	check.c \
	error.c \
	main.c \
	manage_price.c \
	manage_best.c \
	manage_position.c \
	manage_stack.c \
	move_both.c \
	push_utils.c \
	push_utils2.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	swap.c
ROOT_DIR := $(SRC_DIR)
ROOT_OBJ := $(addprefix $(OBJ_DIR)/, $(ROOT_SRC:.c=.o))

ROOT_SRC_BONUS := \
	check_argv.c \
	check_command.c \
	check_push.c \
	check_reverse.c \
	check_rotate.c \
	check_utils.c \
	check_swap.c \
	lst_utils.c \
	main.c 
ROOT_BONUS_DIR := $(SRC_DIR_BONUS)
ROOT_OBJ_BONUS := $(addprefix $(OBJ_DIR_BONUS)/, $(ROOT_SRC_BONUS:.c=.o))


# Combine all source files and object files
SRC := \
	$(ROOT_SRC)
OBJ := \
	$(ROOT_OBJ)

SRC_BONUS := \
	$(ROOT_SRC_BONUS)
OBJ_BONUS := \
	$(ROOT_OBJ_BONUS)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Default target: build the executable
all: libft $(NAME)

# Rule to build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./libft/libft.a

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) ./libft/libft.a

# Rule to build the libft
libft:
	$(MAKE) DEBUG=$(DEBUG) -C ./libft

# Rule to build the libft for release
libft_release:
	$(MAKE) release -C ./libft

# Clean object files and dependencies
clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	$(MAKE) -C ./libft clean

# Remove object files, dependencies, and the executable
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C ./libft fclean

bonus:	libft $(NAME_BONUS)
# Rebuild everything
re: fclean all

# Release target with optimization and stripping
release: CFLAGS += -O2
release: libft_release $(NAME)
	strip libft/libft.a
	strip $(NAME)

# Debug and Optimization Mode Configuration
DEBUG	:= 0

ifeq ($(DEBUG), 1)
    CFLAGS += -g3
endif

# Phony targets
.PHONY: all clean debug fclean re release libft

# Include dependency files
-include $(OBJ:.o=.d)
-include $(OBJ_BONUS:.o=.d)