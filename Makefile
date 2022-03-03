NAME = so_long

LIBF_DIR = libft/
SRC_DIR = srcs/
GNL_DIR = get_next_line/

SRCS = $(MAIN_SRC) $(GNL_SRC)

MAIN_SRC = $(addprefix $(SRC_DIR), $(MAIN))
MAIN = check.c display.c ft_draw.c ft_move.c \
		key_control.c so_long.c start_game.c

GNL_SRC = $(addprefix $(GNL_DIR), $(GNL))
GNL = get_next_line.c get_next_line_utils.c

LIBFT_A = libft.a

LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

OBJ = *.o

FLAGS = -Wall -Wextra -Werror 
INCLUDE = -lmlx -lXext -lX11 -lm

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean

re: fclean all

.PHONY : clean fclean re