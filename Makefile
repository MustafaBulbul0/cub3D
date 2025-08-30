NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Ilibft -Iminilibx-linux -Isrcs -g
RM			= rm -f

SRC_DIR		= srcs
MAP			= srcs/map_control
UTILS		= srcs/utils
FREE		= srcs/free
OBJDIR		= OBJS

SRCS		= $(SRC_DIR)/main.c \
			$(MAP)/control.c \
			$(UTILS)/utils_one.c \
			$(FREE)/ft_free.c

OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBFT		= libft/libft.a
MLX			= minilibx-linux/libmlx.a

MLX_FLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx-linux

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
