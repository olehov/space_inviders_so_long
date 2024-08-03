SRCS = $(wildcard ./ft_window/*.c) $(wildcard ./ft_point/*.c) $(wildcard ./ft_player/*.c) $(wildcard ./ft_game_field/*.c) $(wildcard ./ft_exit_gate/*.c) $(wildcard ./ft_image/*.c) $(wildcard ./ft_utils/*.c) $(wildcard ./ft_enemy/*.c) $(wildcard ./ft_collectible/*.c) render_window.c
OBJS = ${SRCS:.c=.o}
NAME = so_long.a
FTLIBFTNAME = libft_ft.a
CC = cc
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror
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
	$(CC) $(GFLAGS) main.c $(NAME) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_long
	./so_long

run_leaks: $(NAME)
	$(CC) $(GFLAGS) main.c $(NAME) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_long
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long "../maps/valid/big_map.ber"

makeftlibft:
	@make -C $(LIBFTDIR)

clean:
	@cd $(LIBFTDIR) && make clean
	@rm -f *.o $(OBJS) $(OBJSB)
	
fclean: clean
	@cd $(LIBFTDIR) && make fclean
	@rm -f $(NAME) $(NAME) $(OBJSB)
	@rm -f so_long
	
re: fclean all

.PHONY: all test clean fclean re
