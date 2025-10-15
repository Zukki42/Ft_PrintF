# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 17:45:30 by bavirgil          #+#    #+#              #
#    Updated: 2025/10/15 19:22:56 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                FT_PRINTF                                     #
# **************************************************************************** #
# A minimal recreation of the standard printf function.
# This Makefile compiles and archives all source files into libftprintf.a
# **************************************************************************** #

# Compiler setup
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Archiver and removal tools
AR		= ar -rcs
RM		= rm -f

# Output library name
NAME	= libftprintf.a

# Source and object files
SRCS	= ft_printf.c simple.c complex.c
OBJS	= $(SRCS:.c=.o)

# Default rule — build the library
all: $(NAME)

# Create the static library from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "✅ $(NAME) created successfully!"

# Compile .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Remove object files
clean:
	$(RM) $(OBJS)
	@echo "🧹 Object files cleaned up."

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)
	@echo "🗑️  Removed $(NAME)."

# Full rebuild
re: fclean all

# Avoid name conflicts
.PHONY: all clean fclean re
