CC = cc
CFLAGS = -Wall -Wextra -Werror 
#CFLAGS = -fsanitize=address
INCLUDE = -I$(FDF_HEADERS) -I$(LIBFT_HEADER) -I$(GNL_HEADER) -I$(MLX_HEADER)  
LDFLAGS = -L$(LIBFT_DIRECTORY) -lft -L$(GNL_DIRECTORY) -L$(MLX_DIRECTORY) -lmlx -framework OpenGL -framework AppKit
SRCS = ./src/main.c\
		./src/atoi_hex.c\
		./src/divide_height_colour.c\
		./src/open_read.c\
		./src/draw_map.c\
		./src/bresenham.c\
		./src/rotation_move.c\
		./src/key_conversion.c\
		./src/key_conversion2.c\
		./src/init.c\
		./src/rotation.c\

BONUS = ./src_bonus/main_bonus.c\
		./src_bonus/atoi_hex_bonus.c\
		./src_bonus/divide_height_colour_bonus.c\
		./src_bonus/open_read_bonus.c\
		./src_bonus/draw_map_bonus.c\
		./src_bonus/bresenham_bonus.c\
		./src_bonus/rotation_move_bonus.c\
		./src_bonus/key_conversion_bonus.c\
		./src_bonus/key_conversion2_bonus.c\
		./src_bonus/init_bonus.c\
		./src_bonus/rotation_bonus.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
NAME = fdf
BONUS_NAME = fdf_bonus

FDF_HEADERS = ./includes/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)

GNL = $(GNL_DIRECTORY)gnl.a
GNL_DIRECTORY = ./gnl/
GNL_HEADER = $(GNL_DIRECTORY)

MLX = $(MLX_DIRECTORY)libmlx.a
MLX_DIRECTORY = ./minilibx_macos/
MLX_HEADER = $(MLX_DIRECTORY)

all: libft gnl mlx $(NAME)

# %.o:%.c 
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LDFLAGS) $(GNL) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) $(MLX) $(GNL) $(LIBFT) -o $(NAME)


bonus: fclean libft gnl mlx $(BONUS_NAME)
	
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJS) $(LDFLAGS) $(MLX) $(GNL) $(LIBFT) -o $(BONUS_NAME)

libft:
	make -C $(LIBFT_DIRECTORY)

gnl:
	make -C $(GNL_DIRECTORY)

mlx:
	make -C $(MLX_DIRECTORY)

clean:
	make -C $(LIBFT_DIRECTORY) clean
	make -C $(GNL_DIRECTORY) clean
	make -C $(MLX_DIRECTORY) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIRECTORY) fclean
	make -C $(GNL_DIRECTORY) fclean
	make -C $(MLX_DIRECTORY) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft gnl mlx 