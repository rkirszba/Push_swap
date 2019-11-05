# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 12:36:00 by rkirszba          #+#    #+#              #
#    Updated: 2019/03/11 10:29:31 by rkirszba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRCS1 = ps_checker.c \
		get_next_line.c \
		ps_check_args.c \
		ps_check_make_instruct.c \
		ps_execute_check.c \
		ps_free.c \
		ps_instructions.c \
		ps_instructions2.c \
		ps_instructions3.c \
		ps_utils.c \
		ps_utils2.c \
		ps_utils3.c \
		ps_utils4.c \
		ps_visualize.c \
	   	ps_visualize2.c \
		ps_visualize3.c \

SRCS2 = ps_push_swap.c \
		get_next_line.c \
		ps_check_args_ps.c \
		ps_check_args.c \
		ps_check_make_instruct.c \
		ps_exe_and_record.c \
		ps_exe_and_record2.c \
		ps_fill_data.c \
		ps_free.c \
		ps_instructions.c \
		ps_instructions2.c \
		ps_instructions3.c \
		ps_quick_sort_a.c \
		ps_quick_sort_b.c \
		ps_simplify.c \
		ps_simplify2.c \
		ps_split_a.c \
		ps_split_b.c \
		ps_utils_a.c \
		ps_utils_a2.c \
		ps_utils_b.c \
		ps_utils_b2.c \
		ps_utils.c \
		ps_utils2.c \
		ps_utils4.c \
		ps_write_insts.c

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

LIB = libft/libft.a

CC = gcc

CFLAGS += -Wall \
		  -Wextra \
		  -Werror

all: $(NAME) $(NAME2)

$(LIB):
	make -C libft/

$(NAME): $(OBJS1) $(LIB)
	$(CC) -F/Library/Frameworks -framework SDL2 $(CFLAGS) -o $@ $^

$(NAME2): $(OBJS2) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft/
	/bin/rm -f $(OBJS1) $(OBJS2)

fclean: clean
	/bin/rm -f ./libft/libft.a
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: clean re all fclean