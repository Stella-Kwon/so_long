NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS_BONUS = 

SRCS_MANDATORY = srcs/so_long.c \
			srcs/read_map.c \
			srcs/errors.c \
			srcs/map_validation/check_extension.c\
			srcs/map_validation/check_instances_count.c\
			srcs/map_validation/check_position.c\
			srcs/map_validation/check_rantangular.c\
			srcs/map_validation/check_wall.c\
			srcs/img/img_load.c\
			srcs/img/show_img.c\
			srcs/img/img_onoff.c\
			srcs/hooks/player_keyhook.c\
			srcs/hooks/grab_collectives.c\
			srcs/hooks/prints.c\


CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -oo

MLX42FLAGS = -Ofast -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" #- for my M1chip
#MLX42FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all : .delete .mandatory

.delete : 
	@touch .delete
	@rm -f .timestaps .delete_bo

.mandatory: ${SRCS_MANDATORY} $(LIBFT) $(MLX42)
	@cc $(CFLAGS) ${SRCS_MANDATORY} -o ${NAME} $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "\n$(Yellow)-----SO_LONG HAS BEEN CREATED-----$(Ending)\n"

$(LIBFT):
	@make -C libft/

$(MLX42):
	@cd MLX42 && cmake -B build -DDEBUG=1 -DGLFW_FETCH=0 && cmake --build build -j4

#@cd MLX42 && cmake -B build
#cmake -B build 명령어는 현재 디렉토리에 있는 CMakeLists.txt 파일을 사용하여 빌드를 수행하는 대신,
# build라는 이름의 디렉토리에 빌드 관련 파일을 생성하도록 합니다. 즉, -B 옵션을 사용하여 빌드를 위한 디렉토리를 명시적으로 지정할 수 있습니다

#@cd MLX42 && cmake --build build -j4 = @make -C MLX42/build -j4
#일반적으로 cmake --build 명령어는 빌드 디렉토리에서 빌드를 실행합니다.
# 예를 들어, cmake --build build 명령어는 build 디렉토리에서 CMake가 생성한 빌드 시스템을 사용하여 프로젝트를 빌드합니다.

bonus : .delete_bo .timestaps

.delete_bo : 
	@touch .delete_bo
	@rm -f .mandatory .delete

.timestaps : ${SRCS_BONUS} $(LIBFT) $(MLX42)
	@cc $(CFLAGS) ${SRCS_BONUS} -o ${NAME} $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "\n$(GREEN)-----SO_LONG(BONUS) HAS BEEN CREATED-----$(Ending)\n"

clean:
	@make clean -C libft
	@make clean -C MLX42/build
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store
	@rm -f .mandatory .delete .delete_bo .timestaps

#"dSYM"은 "debug symbol"의 약어로, 프로그램의 디버그 정보를 포함하고 있는 이 파일들은 주로 프로그램의 디버깅 및 프로파일링을 위해 사용됩니다. 

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