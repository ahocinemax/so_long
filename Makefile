NAME		=	so_long
GNL_DIR		=	get_next_line/
LIB_DIR		=	libft/
SRC_DIR		=	srcs/
MLX_DIR		=	mlx/

SRCS		=	$(GNL_SRC) $(MAIN_SRC)

MAIN_SRC	= 	$(addprefix $(SRC_DIR), $(MAIN))
MAIN		=	ft_utils.c ft_check.c ft_display.c ft_draw.c \
				ft_move.c ft_key_control.c so_long.c \
				ft_start_game.c ft_check2.c

GNL_SRC		=	$(addprefix $(GNL_DIR), $(GNL))
GNL			=	get_next_line.c get_next_line_utils.c

OBJ			=	get_next_line.o get_next_line_utils.o ft_utils.o \
				ft_check.o ft_display.o ft_draw.o ft_move.o \
				ft_key_control.o so_long.o ft_start_game.o ft_check2.o

LIBMLX_A	=	libmlx.a
LIBFT_A		=	libft.a
LIBMLX		=	$(addprefix $(MLX_DIR), $(LIBMLX_A))
LIBFT		=	$(addprefix $(LIB_DIR), $(LIBFT_A))


CFLAGS		=	-Wall -Wextra -Werror -g3
INCLUDE		=	-lXext -lX11 -lm
CC			=	gcc

END			=	'\033[0m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
GRAY		=	'\033[2;37m'
CURSIVE		=	'\033[3m'

all: $(NAME)

$(OBJ): $(SRCS)
	@echo $(CURSIVE)$(GREEN) "     ~ Making object files..." $(END)
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(LIB_DIR)..." $(END)
	make -C $(LIB_DIR)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(MLX_DIR)..." $(END)
	make -C $(MLX_DIR)
	@echo $(CURSIVE)$(GREEN) "     ~ Compiling $(NAME)..." $(END)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(INCLUDE) -o $(NAME)
	@echo $(YELLOW)"~ Game compiled ~"$(END)

clean:
	@echo $(CURSIVE)$(GREEN) "     ~ Removing object files..." $(END)
	rm -f $(OBJ)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean


fclean: clean
	@echo $(CURSIVE)$(GREEN) "     ~ Removing $(NAME)..." $(END)
	rm -rf $(NAME) 
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY : clean fclean re
