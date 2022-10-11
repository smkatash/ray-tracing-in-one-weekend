# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/10/07 18:53:21 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = minirt
SRC = main.c camera.c ray_tracing.c scene.c sphere_intersect.c sphere.c utils.c vector.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx
	gcc $(OBJ) ./libft/libft.a -o minirt  $(FLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

image: $(NAME)
	./$(NAME)

re: fclean all
