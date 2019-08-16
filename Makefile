NAME = libps.a

CHECKER = checker checker.c

PUSH_SWAP = push_swap push_swap.c

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

LIB = libft/libft.a

LIBPRINTF = libft/ft_printf/libftprintf.a

LIBPATH = libft/

LIBPRINTFPATH = libft/ft_printf/

HEADER =

SRCS = checker.c push_swap.c create_lst.c input_parser.c remove_lst.c \
	   actions3.c actions2.c actions4.c actions1.c error_management.c input_functions.c \
	   jump_table.c is_sorted.c quicksort2.c quicksort1.c list_opp.c \
	   action_optimisation.c flag_options.c get_colour.c quicksort4.c quicksort5.c \
	   quicksort3.c visual_functions.c\

OBJS = checker.o push_swap.o create_lst.o input_parser.o remove_lst.o \
       actions3.o actions2.o actions4.o actions1.o error_management.o input_functions.o \
       jump_table.o is_sorted.o quicksort2.o quicksort1.o list_opp.o \
       action_optimisation.o flag_options.o get_colour.o quicksort4.o quicksort5.o \
       quicksort3.o visual_functions.o\
	  

all: $(NAME)

$(NAME):
	make -C $(LIBPATH) all
	make -C $(LIBPRINTFPATH) all
	$(CC) $(CFLAGS) $(SRCS) $(HEADER)
	cp $(LIB) $(NAME)
	cp $(LIBPRINTF) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	make clean
	$(CC) -I. -o $(CHECKER) $(NAME) $(LIB) $(LIBPRINTF)
	$(CC) -I. -o $(PUSH_SWAP) $(NAME) $(LIB) $(LIBPRINTF)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all
