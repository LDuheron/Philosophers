#############################################

NAME := philo

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj
SRCS        := \
	main.c								\
	exit.c								\
	initialization.c					\
	monitor.c							\
	philo.c								\
	philo_utils.c						\
	status.c							\
	check_input/input_is_valid.c		\
	check_input/input_is_valid_utils.c	\

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := clang
CFLAGS      := -pthread -Wall -Wextra -Werror -g3
CPPFLAGS    := -I include

#############################################

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#############################################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#############################################

.PHONY: clean fclean re
.SILENT:

#############################################
