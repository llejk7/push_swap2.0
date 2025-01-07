# Program name
NAME        = push_swap

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Directories
SRCDIR      = src
OBJDIR      = obj
INCDIR      = inc
LIBFTDIR    = libft

# Source files
SRCS        = src/main.c \
              src/operations/push.c \
              src/operations/reverse_rotate.c \
              src/operations/rotate.c \
              src/operations/swap.c \
              src/sorting/radix_sort.c \
              src/sorting/simple_sort.c \
              src/sorting/small_sort.c \
              src/utils/assign_indices.c \
              src/utils/error_handling.c \
              src/utils/get_max_bits.c \
              src/utils/input_validation.c \
              src/utils/parse_input.c \
              src/utils/validation_utils.c

# Object files
OBJS        = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Library
LIBFT       = $(LIBFTDIR)/libft.a

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus