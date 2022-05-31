	# Library Name #
NAME	= 	cub3D

	# Compilator #
COMPILER	= 	cc

	# Variables #
SRCS		= 	main.c \
				check/check_celling_floor.c \
				check/check_file.c \
				check/check_map.c \
				check/check_order_in_file.c \
				check/check_rgb.c \
				check/check_walls.c \
				errors/print_error.c \
				free/free.c \
				free/free_img.c \
				free/free_structs.c \
				free/free_utils.c \
				game/keys.c \
				init/init_game.c \
				init/init_map.c \
				init/init_structs.c \
				init/init_structs2.c \
				parsing/collect_celling_floor.c \
				parsing/collect_file.c \
				parsing/collect_map.c \
				parsing/collect_map_lines.c \
				parsing/collect_walls.c \
				utils/utils_digits.c \
				utils/utils_gnl.c \
				utils/utils_is.c \
				utils/utils_mem.c \
				utils/utils_split.c \
				utils/utils_split_charset.c \
				utils/utils_str.c \
				utils/utils_str2.c \
				utils/utils_str3.c \
				utils/utils_write.c \

INCLUDES 	= 	includes/cub3D.h

	# Colors Foreground #
DEFAULT		=	\033[0;39m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
RED_B		=	\033[1;31m
L_RED		=	\033[0;91m
GREEN		=	\033[0;32m
GREEN_B		=	\033[1;32m
L_GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
L_YELLOW	=	\033[0;93m
BLUE		=   \033[0;34m
BLUE_B		=	\033[1;34m
L_BLUE		=   \033[0;94m
PINK		=	\033[0;35m
L_PINK		=	\033[0;95m
SKY			=   \033[0;36m
SKY_B		=	\033[1;36m
L_CYAN		=   \033[0;96m
GREY		=	\033[0;37m
D_GREY		=	\033[0;90m
WHITE		=	\033[0;97m
RESET		=	\e[0m

	# Colors Background #
NOIR		=	\033[0;40m
ROUGE		=	\033[0;41m
L_ROUGE		=	\033[0;101m
VERT		=	\033[0;42m
L_VERT		=	\033[0;102m
JAUNE		=	\033[0;43m
L_JAUNE		=	\033[0;103m
BLEU		=	\033[0;44m
L_BLEU		=	\033[0;104m
ROSE		=	\033[0;45m
L_ROSE		=	\033[0;105m
CYAN		=	\033[0;46m
L_CYAN		=	\033[0;106m
GRIS		=	\033[0;100m
BLANC		=	\033[0;107m

	# Objects #
OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})
DEP		= $(OBJS:.o=.d)

	# Flags #

FLAGS		= 	-g -Wall -Werror -Wextra
FL_MLX		=	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

	# Rules #
all:		${NAME}
			@printf "$(L_PINK)<3 <3 $(RESET)"
			@printf "$(RED_B)Manu et Dim le sang$(RESET)"
			@printf "$(L_PINK) <3 <3 \n$(RESET)"

$(NAME):	${OBJS} ${INCLUDES}
			@make -C ./mlx
			${COMPILER} ${FLAGS} -I includes ${OBJS} -o $(NAME) $(FL_MLX)
			@printf "\n$(GREEN)████████████████████████████████████████████████████████  ✨ ✨ ✨  C'EST MERVEILLEUSEMENT BIEN COMPILE  ✨ ✨ ✨  █████████████████████████████████████████████$(RESET)"
			@printf	"\n\n\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                                                                                                                                                                $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)  $(RESET)$(NOIR)    $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                                  $(RESET)$(GRIS)  $(RESET)$(NOIR)        $(RESET)$(GRIS)  $(RESET)$(NOIR)                                                                                                                  $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(ROSE)  $(RESET)$(GRIS)        $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(ROSE)  $(RESET)$(GRIS)        $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                            $(RESET)$(ROUGE)                        $(RESET)$(NOIR)                                                                                                            $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(ROUGE)                        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(ROUGE)                        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                            $(RESET)$(ROUGE)                        $(RESET)$(NOIR)                                                                                                            $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(ROUGE)                    $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)                      $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)        $(RESET)$(ROSE)    $(RESET)$(GRIS)  $(RESET)$(ROSE)    $(RESET)$(ROUGE)      $(RESET)$(NOIR)        $(RESET)$(ROUGE)      $(RESET)$(ROSE)    $(RESET)$(GRIS)  $(RESET)$(ROSE)    $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)                      $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                      $(RESET)$(ROSE)  $(RESET)$(NOIR)            $(RESET)$(ROSE)        $(RESET)$(NOIR)            $(RESET)$(ROSE)  $(RESET)$(NOIR)                                                        $(RESET)$(JAUNE)                $(RESET)$(NOIR)                              $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)  $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROSE)        $(RESET)$(NOIR)  $(RESET)$(GRIS)              $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(JAUNE)                $(RESET)$(NOIR)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)  $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)              $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                              $(RESET)$(ROSE)          $(RESET)$(NOIR)    $(RESET)$(ROSE)    $(RESET)$(NOIR)                                                                  $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)                              $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(ROSE)                    $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)              $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(JAUNE)                $(RESET)$(NOIR)    $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(ROSE)        $(RESET)$(BLEU)  $(RESET)$(ROSE)            $(RESET)$(NOIR)  $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)              $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(JAUNE)                $(RESET)$(NOIR)    $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                              $(RESET)$(ROSE)      $(RESET)$(BLANC)    $(RESET)$(ROSE)  $(RESET)$(BLEU)  $(RESET)$(ROSE)      $(RESET)$(NOIR)                                                                            $(RESET)$(JAUNE)    $(RESET)$(NOIR)                              $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)  $(RESET)$(ROSE)    $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(BLANC)    $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)            $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)    $(RESET)$(ROSE)        $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)$(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)            $(RESET)$(NOIR)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                              $(RESET)$(ROSE)    $(RESET)$(NOIR)    $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(ROUGE)  $(RESET)$(NOIR)                                                                $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)                              $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)    $(RESET)$(ROSE)  $(RESET)$(NOIR)      $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)              $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(JAUNE)                    $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(NOIR)  $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)          $(RESET)$(GRIS)                $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(JAUNE)                    $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                                                                                                          $(RESET)$(BLANC)    $(RESET)$(BLEU)    $(RESET)$(BLANC)    $(RESET)$(JAUNE)    $(RESET)$(BLANC)    $(RESET)$(BLEU)    $(RESET)$(ROUGE)  $(RESET)$(BLEU)  $(RESET)$(BLANC)    $(RESET)$(NOIR)                      $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(BLANC)    $(RESET)$(BLEU)    $(RESET)$(BLANC)    $(RESET)$(JAUNE)    $(RESET)$(BLANC)    $(RESET)$(BLEU)        $(RESET)$(BLANC)    $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(BLANC)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)  $(RESET)$(BLANC)          $(RESET)$(ROUGE)  $(RESET)$(BLEU)        $(RESET)$(BLANC)        $(RESET)$(GRIS)      $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                                                                                                      $(RESET)$(BLANC)        $(RESET)$(BLEU)    $(RESET)$(BLANC)        $(RESET)$(BLANC)    $(RESET)$(BLEU)  $(RESET)$(ROUGE)  $(RESET)$(BLEU)    $(RESET)$(BLANC)        $(RESET)$(NOIR)                  $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(BLANC)  $(RESET)$(ROUGE)  $(RESET)$(BLANC)    $(RESET)$(BLEU)                            $(RESET)$(BLANC)        $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)        $(RESET)$(NOIR)                                        $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)      $(RESET)$(BLANC)    $(RESET)$(BLANC)    $(RESET)$(BLEU)    $(RESET)$(ROUGE)  $(RESET)$(BLEU)                      $(RESET)$(BLANC)        $(RESET)$(GRIS)        $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)\n"
			@printf "$(NOIR)                      $(RESET)$(ROSE)          $(RESET)$(BLANC)              $(RESET)$(ROSE)            $(RESET)$(NOIR)                                            $(RESET)$(BLANC)    $(RESET)$(NOIR)    $(RESET)$(BLEU)  $(RESET)$(ROUGE)  $(RESET)$(BLEU)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)              $(RESET)$(NOIR)    $(RESET)$(BLANC)    $(RESET)$(NOIR)              $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)           $(RESET)$(NOIR)  $(RESET)$(ROSE)             $(RESET)$(BLANC)  $(RESET)$(ROUGE)          $(RESET)$(BLANC)  $(RESET)$(ROSE)            $(RESET)$(NOIR)  $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(BLANC)    $(RESET)$(GRIS)    $(RESET)$(BLEU)                $(RESET)$(ROUGE)    $(RESET)$(BLEU)        $(RESET)$(GRIS)    $(RESET)$(BLANC)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)             $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(ROUGE)  $(RESET)$(JAUNE)          $(RESET)$(ROUGE)  $(RESET)$(ROSE)          $(RESET)$(NOIR)    $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)$(NOIR)  $(RESET)$(JAUNE)    $(RESET)$(GRIS)    $(RESET)$(BLEU)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)        $(RESET)$(GRIS)    $(RESET)$(JAUNE)    $(RESET)$(GRIS)  $(RESET)$(NOIR)  $(RESET)$(GRIS)          $(RESET)\n"
			@printf "$(NOIR)                     $(RESET)$(ROSE)           $(RESET)$(BLANC)  $(RESET)$(ROUGE)          $(RESET)$(BLANC)  $(RESET)$(ROSE)          $(RESET)$(NOIR)                                              $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(BLEU)      $(RESET)$(ROUGE)          $(RESET)$(BLEU)            $(RESET)$(NOIR)    $(RESET)$(JAUNE)    $(RESET)$(NOIR)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                            $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(BLEU)      $(RESET)$(ROUGE)            $(RESET)$(BLEU)          $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)         $(RESET)$(NOIR)        $(RESET)$(BLANC)  $(RESET)$(NOIR)      $(RESET)$(ROSE)    $(RESET)$(NOIR)    $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                            $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(BLEU)  $(RESET)$(ROUGE)  $(RESET)$(BLEU)  $(RESET)$(ROUGE)            $(RESET)$(BLEU)          $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)       $(RESET)$(NOIR)          $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                            $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(BLEU)        $(RESET)$(ROUGE)          $(RESET)$(BLEU)          $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(ROUGE)  $(RESET)$(NOIR)    $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                            $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(BLEU)          $(RESET)$(ROUGE)        $(RESET)$(BLEU)    $(RESET)$(ROUGE)  $(RESET)$(BLEU)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(NOIR)    $(RESET)$(ROUGE)      $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                            $(RESET)$(JAUNE)    $(RESET)$(NOIR)  $(RESET)$(ROUGE)  $(RESET)$(BLEU)      $(RESET)$(ROUGE)  $(RESET)$(BLEU)                    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(ROUGE)  $(RESET)$(NOIR)    $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROSE)        $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                          $(RESET)$(NOIR)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(BLEU)          $(RESET)$(ROUGE)      $(RESET)$(BLEU)            $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)              $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)       $(RESET)$(NOIR)          $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(NOIR)  $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                        $(RESET)$(NOIR)      $(RESET)$(ROUGE)      $(RESET)$(BLEU)    $(RESET)$(ROUGE)  $(RESET)$(BLEU)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)    $(RESET)$(ROUGE)  $(RESET)$(BLEU)      $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                      $(RESET)$(NOIR)      $(RESET)$(ROUGE)        $(RESET)$(BLEU)      $(RESET)$(ROUGE)    $(RESET)$(BLEU)        $(RESET)$(ROUGE)    $(RESET)$(BLEU)      $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                    $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(ROUGE)          $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                  $(RESET)$(GRIS)        $(RESET)$(ROUGE)          $(RESET)$(BLEU)        $(RESET)$(ROUGE)      $(RESET)$(BLEU)        $(RESET)$(ROUGE)  $(RESET)$(BLEU)    $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)            $(RESET)$(NOIR)  $(RESET)$(ROSE)          $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                $(RESET)$(GRIS)            $(RESET)$(ROUGE)        $(RESET)$(BLEU)        $(RESET)$(ROUGE)      $(RESET)$(BLEU)      $(RESET)$(ROUGE)    $(RESET)$(BLEU)    $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)    $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(JAUNE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)        $(RESET)$(NOIR)  $(RESET)$(ROUGE)                              $(RESET)$(GRIS)                $(RESET)$(ROUGE)      $(RESET)$(BLEU)          $(RESET)$(ROUGE)        $(RESET)$(BLEU)          $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(JAUNE)  $(RESET)$(NOIR)  $(RESET)$(JAUNE)    $(RESET)$(NOIR)    $(RESET)$(ROSE)      $(RESET)$(NOIR)    $(RESET)$(ROUGE)                            $(RESET)$(GRIS)                    $(RESET)$(ROUGE)    $(RESET)$(BLEU)            $(RESET)$(ROUGE)      $(RESET)$(BLEU)          $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(NOIR)  $(RESET)$(JAUNE)  $(RESET)$(NOIR)  $(RESET)$(JAUNE)  $(RESET)$(NOIR)  $(RESET)$(JAUNE)    $(RESET)$(NOIR)  $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                          $(RESET)$(GRIS)                $(RESET)$(ROUGE)  $(RESET)$(GRIS)  $(RESET)$(ROUGE)      $(RESET)$(BLEU)            $(RESET)$(ROUGE)      $(RESET)$(BLEU)          $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)         $(RESET)$(NOIR)  $(RESET)$(JAUNE)  $(RESET)$(NOIR)      $(RESET)$(BLANC)  $(RESET)$(NOIR)    $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                        $(RESET)$(GRIS)    $(RESET)$(NOIR)  $(RESET)$(GRIS)        $(RESET)$(ROUGE)  $(RESET)$(GRIS)    $(RESET)$(ROUGE)        $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)         $(RESET)$(NOIR)    $(RESET)$(BLANC)            $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                        $(RESET)$(GRIS)              $(RESET)$(ROUGE)    $(RESET)$(GRIS)  $(RESET)$(ROUGE)        $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(ROSE)  $(RESET)$(ROUGE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                          $(RESET)$(GRIS)          $(RESET)$(ROUGE)  $(RESET)$(GRIS)    $(RESET)$(ROUGE)          $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)  $(RESET)$(NOIR)        $(RESET)$(BLANC)    $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(ROSE)  $(RESET)$(ROUGE)    $(RESET)$(NOIR)  $(RESET)$(ROUGE)                            $(RESET)$(GRIS)            $(RESET)$(ROUGE)            $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)           $(RESET)$(BLANC)              $(RESET)$(NOIR)  $(RESET)$(BLANC)  $(RESET)$(ROSE)  $(RESET)$(ROUGE)    $(RESET)$(NOIR)  $(RESET)$(ROUGE)                              $(RESET)$(GRIS)        $(RESET)$(ROUGE)              $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)  $(RESET)$(ROSE)         $(RESET)$(NOIR)                $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)  $(RESET)$(NOIR)  $(RESET)$(ROSE)  $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                $(RESET)$(GRIS)      $(RESET)$(ROUGE)              $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                 $(RESET)$(NOIR)  $(RESET)$(ROSE)             $(RESET)$(BLANC)              $(RESET)$(ROSE)    $(RESET)$(NOIR)  $(RESET)$(ROSE)      $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                $(RESET)$(GRIS)  $(RESET)$(ROUGE)                $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                 $(RESET)$(NOIR)  $(RESET)$(ROSE)             $(RESET)$(BLANC)              $(RESET)$(ROSE)            $(RESET)$(NOIR)  $(RESET)$(ROUGE)                                                  $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                   $(RESET)$(NOIR)                                       $(RESET)$(ROUGE)                                                    $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"
			@printf "$(ROUGE)                                                                                                              $(RESET)$(BLEU)                            $(RESET)$(ROUGE)                      $(RESET)\n"

		 	@printf "\n\n$(SKY)█████████████████████████████████████████████████████████  😊 😊 😊  PENSEE DU JOUR POUR TE FAIRE SOURIRE  😊 😊 😊  ███████████████████████████████████████████$(RESET)"
			@printf "\n\n$(BLUE_B)If it bleeds 🩸, we can kill it 💀 !\n\n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)La vie passe, la moulinette trepasse !\n\n$(RESET)"

-include $(DEP)

objs/%.o:		srcs/%.c
					@mkdir -p $(dir $@)
					@${COMPILER} -MMD ${FLAGS} -I includes -o $@ -c $<
# -lmlx -lbass
norme:
			@norminette srcs/*
			@norminette includes/*
			@printf "$(YELLOW)\nLa normalité est une expérience plus extrême que ce que les gens veulent communément admettre.\n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)La vie passe, la norminette trepasse !\n$(RESET)"

clean:
			@make -C ./mlx clean
			rm -f ${OBJS}
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"
fclean:
			@make -C ./mlx clean
			rm -f ${OBJS}
			rm -f ${NAME}
			rm -rf objs
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"

re:			fclean all
			@printf "$(YELLOW)\nAimer, désirer, c’est aussi souffrir, et être prêt à recommencer... \n$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"

.PHONY: 	all norme clean fclean re
