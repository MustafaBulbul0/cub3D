NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Ilibft -Iminilibx-linux -Isrcs -g
RM			= rm -f

SRC_DIR		= srcs
MAP			= srcs/map_control
GAME		= srcs/game
UTILS		= srcs/utils
FREE		= srcs/free
OBJDIR		= OBJS

SRCS		= $(SRC_DIR)/main.c \
			$(MAP)/texture_control.c $(MAP)/map_control.c $(MAP)/map_hole_control.c \
			$(MAP)/map_file_control.c \
			$(GAME)/start_game.c $(GAME)/key_press.c $(GAME)/raycasting.c \
			$(GAME)/load_textures.c $(GAME)/cast_single_ray.c $(GAME)/bonus.c \
			$(UTILS)/utils_one.c $(UTILS)/read_file.c $(UTILS)/utils_two.c \
			$(UTILS)/init_map_texture.c $(UTILS)/utils_three.c $(UTILS)/game_utils.c \
			$(FREE)/ft_free.c

OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBFT		= libraries/libft/libft.a
MLX			= libraries/minilibx-linux/libmlx.a

MLX_FLAGS	= -Llibraries/minilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C libraries/libft

$(MLX):
	$(MAKE) -C libraries/minilibx-linux

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C libraries/libft
	$(MAKE) clean -C libraries/minilibx-linux

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libraries/libft

re: fclean all

.PHONY: all clean fclean re
