NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code
MLX_DIR	= ./MLX42
MLX	:= $(MLX_DIR)/libmlx42.a
HEADERS	:= -I$(MLX)
MLX_FLAGS	:= -ldl -pthread -lm
SRCS	:= so_long.c utils/get_next_line.c utils/get_next_line_utils.c utils/ft_printf.c utils/ft_check_d_i.c read_map.c check_map.c floodfill.c load_images.c print_map.c hook.c check_errors.c collects.c
OBJS	:= ${SRCS:.c=.o}
all: $(NAME)
libmlx:
	@make -C $(MLX_DIR)
%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)
re: clean all
.PHONY: all, clean, fclean, re, libmlx