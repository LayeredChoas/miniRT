# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 13:26:50 by ayennoui          #+#    #+#              #
#    Updated: 2020/11/07 14:22:10 by ayennoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./srcs/camera.c \
		./srcs/ft_normal.c \
		./srcs/ft_inter.c \
		./srcs/ft_obj_h.c \
		./srcs/ft_atoi.c \
		./srcs/ft_atoi_float.c \
		./srcs/ft_num_color.c \
		./srcs/ft_ray.c \
		./srcs/ft_vec_ops.c \
		./srcs/ft_vec_ops1.c \
		./srcs/ft_return.c \
		./srcs/ft_math.c \
		./srcs/ft_rt_and_mv.c \
		./srcs/bmp_img.c \
		./srcs/ft_strcmp.c \
		./srcs/ft_strlen.c \
		./srcs/phong_col.c \
		./srcs/shadows.c \
		./srcs/ft_inter1.c \
		./srcs/ft_objs_normal.c \
		./srcs/ft_rest_others.c \
		./srcs/ft_rest_objs.c \
		./srcs/ft_add_li_ca.c \
		./srcs/ft_add_obj.c \
		./srcs/ft_vec_ops2.c \
		./srcs/ft_free.c \
		./srcs/file_var/ft_col_fill.c \
		./srcs/file_var/ft_cor_fill.c \
		./srcs/file_var/ft_handling_file.c \
		./srcs/file_var/ft_objs_1.c \
		./srcs/file_var/ft_objs_2.c \
		./srcs/file_var/ft_objs_3.c \
		./srcs/ft_hooks.c \
		./srcs/ft_print_all.c \
		main.c
		
HEADER = ./include/ft_math.h \
		./include/ft_minirt.h \
		./include/ft_struct.h \
		./include/get_next_line.h 
		
GNL_HEADER = ./include/get_next_line.h 
		

RED = \033[0;31m
NC = \033[0m
BLUE = \033[0;34m
GREAN = \033[0;32m
YELLOW = \033[0;33m

FLAGS = -Wall -Werror -Wextra

COMP = gcc $(FLAGS) -g -I /user/local/include

COMP_MLX = -lmlx -framework OpenGL -framework Appkit

LIB = ./libs/gnl.a

NAME = miniRT
IMAGE = image.bmp

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :	$(OBJ) $(HEADER)
			@$(COMP) $(LIB) $(COMP_MLX) $(OBJ) -o $(NAME)
			@echo "$(GREAN)minirt been created$(NC)"
			@echo "$(GREAN) press 'm' for transition, press 'r' for rotation, press 's' for size$(NC)"
			@echo "$(GREAN) press 'x, y or z' for mouvement or rotation at the selected axe$(NC)"
%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled "$<" successfully!$(NC)"

norm : 
	norminette $(SRC) $(HEADER)
clean:
	@rm -f $(OBJ)
	@echo "${RED}Object files been removed${NC}"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(IMAGE)
	@echo "${RED}minirt been removed${NC}"

re: fclean all
