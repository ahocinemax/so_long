NAME = so_long
GNL_DIR = get_next_line/
LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = obj/
MLX_DIR = mlx/

SRCS = $(GNL_SRC) $(MAIN_SRC)

MAIN_SRC = $(addprefix $(SRC_DIR), $(MAIN))
MAIN = ft_utils.c ft_check.c ft_display.c ft_draw.c \
		ft_move.c ft_key_control.c so_long.c \
		ft_start_game.c \
		

GNL_SRC = $(addprefix $(GNL_DIR), $(GNL))
GNL = get_next_line.c get_next_line_utils.c

LIBFT_A = libft.a
LIBFT  = $(addprefix $(LIB_DIR), $(LIBFT_A))

LIBMLX_A = libmlx.a
LIBMLX = $(addprefix $(MLX_DIR), $(LIBMLX_A))

OBJ = *.o

FLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -lXext -lX11 -lm

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making $(LIB_DIR)..." $(NONE)
	@make -C $(LIB_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Making $(MLX_DIR)..." $(NONE)
	@make -C $(MLX_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(INCLUDE) -o $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files..." $(NONE)
	@mkdir $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@echo $(YELLOW)"- Game compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJ_DIR)$(OBJ)
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean


fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) $(OBJ_DIR)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY : clean fclean re
