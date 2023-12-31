# **************************************************************************** #
# 	Makefile based on clemedon's Makefile tutorial							   #
# **************************************************************************** #

NAME		:= push_swap

# **************************************************************************** #
# 	SOURCES																	   #
# **************************************************************************** #

SRC_DIR		:= src
SRCS		:= \
				main.c \
				parsing.c \
				packed.c \
				lis_alloc.c \
				lis_compute.c \
				solver.c \
				insertion.c \
				transfer.c \
				stack/alloc.c \
				stack/manip.c \
				stack/ps.c \
				stack/r.c \
				stack/rr.c \
				stack/minmax.c \
				phases.c \
				small_sort.c \
				array_checking.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

INCS		:=	include

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

# **************************************************************************** #
# 	LIBRARIES																   #
# **************************************************************************** #

LIB_DIR		?= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))lib
LIBS		:= ft
LIB_TARGETS	:= libft/libft.a
LIB_TARGETS	:= $(addprefix $(LIB_DIR)/,$(LIB_TARGETS))
LIB_INCS	:= libft/include/
INCS		+= $(addprefix $(LIB_DIR)/,$(LIB_INCS))

# **************************************************************************** #
# 	COMPILATION																   #
# **************************************************************************** #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_TARGETS)))
LDLIBS		:= $(addprefix -l,$(LIBS))
AR			:= ar -rcs

# **************************************************************************** #
# 	UTILITIES																   #
# **************************************************************************** #

RM			:= rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP		= @mkdir -p $(@D)

# **************************************************************************** #
# 	RECIPIES :D																   #
# **************************************************************************** #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(LIB_TARGETS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

-include $(DEPS)

clean:
	make fclean -C $(LIB_DIR)/libft
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
# 	DEPENDENCIES :3															   #
# **************************************************************************** #

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(LIB_DIR)/libft/: | $(LIB_DIR)
	git clone git@github.com:vchakhno/libft.git $(LIB_DIR)/libft

.SECONDEXPANSION:
$(LIB_TARGETS): $(LIB_DIR)/%.a: | $(LIB_DIR)/$$(dir %.a)
	make LIB_DIR=$(LIB_DIR) -C $(dir $@)
