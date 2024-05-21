NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS_BONUS = srcs/so_long_bonus.c \
			srcs/read_map.c \
			srcs/errors.c \
			srcs/map_validation/check_extension.c\
			srcs/map_validation/check_instances_count_bonus.c\
			srcs/map_validation/check_position.c\
			srcs/map_validation/check_rantangular.c\
			srcs/map_validation/map_too_big.c\
			srcs/map_validation/check_wall.c\
			srcs/img/img_load_bonus.c\
			srcs/img/show_img_bonus.c\
			srcs/img/img_onoff.c\
			srcs/hooks/player_keyhook_bonus.c\
			srcs/hooks/grab_collectives.c\
			srcs/hooks/prints.c\
			srcs/hooks/enemy_loophook.c\
			srcs/hooks/enemy_move.c\
			srcs/img/show_img_bonus2.c\

SRCS_MANDATORY = srcs/so_long.c \
			srcs/read_map.c \
			srcs/errors.c \
			srcs/map_validation/check_extension.c\
			srcs/map_validation/check_instances_count.c\
			srcs/map_validation/check_position.c\
			srcs/map_validation/check_rantangular.c\
			srcs/map_validation/map_too_big.c\
			srcs/map_validation/check_wall.c\
			srcs/img/img_load.c\
			srcs/img/show_img.c\
			srcs/img/img_onoff.c\
			srcs/hooks/player_keyhook.c\
			srcs/hooks/grab_collectives.c\
			srcs/hooks/prints.c\
			

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -oo

MLX42FLAGS = -Ofast -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all : .delete .mandatory

.delete : 
	@touch .delete
	@rm -f .timestaps .delete_bo

.mandatory: ${SRCS_MANDATORY} $(LIBFT) $(MLX42)
	@touch .mandatory
	@cc $(CFLAGS) ${SRCS_MANDATORY} -o ${NAME} $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "\n$(Yellow)-----SO_LONG HAS BEEN CREATED-----$(Ending)\n"

$(LIBFT):
	@make -C libft/

$(MLX42):
	@cd MLX42 && cmake -B build -DDEBUG=1 -DGLFW_FETCH=0 && cmake --build build -j4

bonus : .delete_bo .timestaps

.delete_bo : 
	@touch .delete_bo
	@rm -f .mandatory .delete

.timestaps : ${SRCS_BONUS} $(LIBFT) $(MLX42)
	@touch .timestaps
	@cc $(CFLAGS) ${SRCS_BONUS} -o ${NAME} $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "\n$(GREEN)-----SO_LONG(BONUS) HAS BEEN CREATED-----$(Ending)\n"
 
clean:
	@make clean -C libft
	@make clean -C MLX42/build
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store
	@rm -f .mandatory .delete .delete_bo .timestaps

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}
	@rm -rf MLX42/build
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus check_bonus check_mandatory

Red = \033[0;31m
Green = \033[0;32m
Yellow = \033[0;33m
Blue = \033[0;34m
Magenta = \033[0;35m
Cyan = \033[0;36m
White = \033[0;37m
Ending = \033[0m