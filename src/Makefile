SRCS = $(wildcard ./ft_window/*.c) $(wildcard ./ft_point/*.c) $(wildcard ./ft_player/*.c) $(wildcard ./ft_game_field/*.c) $(wildcard ./ft_exit_gate/*.c) $(wildcard ./ft_image/*.c) $(wildcard ./ft_utils/*.c) render_window.c
OBJS = ${SRCS:.c=.o}
NAME = so_long.a
FTLIBFTNAME = libft_ft.a
CC = cc
LIBC = ar rcs
CFLAGS = -Wall -Wextra
LIBFTDIR = ../ft_libft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): makeftlibft $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(FTLIBFTNAME) .
	@mv $(FTLIBFTNAME) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

run: $(NAME)
	@rm -f a.out
	$(CC) $(GFLAGS) main.c $(NAME) -Lminilibx-linux -lmlx_Linux -lX11 -lXext
	./a.out

run_leaks: $(NAME)
	@rm -f a.out
	$(CC) $(GFLAGS) main.c $(NAME) -Lminilibx-linux -lmlx_Linux -lX11 -lXext
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./a.out

makeftlibft:
	@make -C $(LIBFTDIR)

clean:
	@cd $(LIBFTDIR) && make clean
	@rm -f *.o $(OBJS) $(OBJSB)
	
fclean: clean
	@cd $(LIBFTDIR) && make fclean
	@rm -f $(NAME) $(NAME) $(OBJSB)
	
re: fclean all

.PHONY: all test clean fclean re
