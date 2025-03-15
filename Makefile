CC= cc
FLAGS= -Wall -Werror -Wextra -O3 

HEADER= so_long.h
HEADER_B= bonus/so_long_bonus.h

SRC=	so_long.c print_error.c print_utils.c get_next_line.c \
		get_next_line_utils.c input_utils.c process_map.c \
		process_utils.c parse_path.c game_loop.c build_map_utils.c \
		game_loop_utils.c build_map_helpers.c ft_itoa.c \
		build_more_helpers.c destroy.c

SRC_B=	bonus/so_long_bonus.c bonus/print_error_bonus.c bonus/print_utils_bonus.c bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c bonus/input_utils_bonus.c bonus/process_map_bonus.c \
		bonus/process_utils_bonus.c bonus/parse_path_bonus.c bonus/game_loop_bonus.c bonus/build_map_utils_bonus.c \
		bonus/game_loop_utils_bonus.c bonus/build_map_helpers_bonus.c bonus/ft_itoa_bonus.c \
		bonus/build_more_helpers_bonus.c bonus/destroy_bonus.c \
		bonus/food_anim_bonus.c

OBJ=$(SRC:.c=.o)
OBJ_B=$(SRC_B:.c=.o)

NAME= so_long
BONUS= so_long_bonus

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I. .mlx_linux/libmlx.a -lXext -lX11 -lm -o $@

$(BONUS): $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -I. .mlx_linux/libmlx.a -lXext -lX11 -lm -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_B)
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME) $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_B)

re: fclean all

.PHONY: clean