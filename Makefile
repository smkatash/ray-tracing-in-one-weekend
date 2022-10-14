# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 09:01:25 by kanykei           #+#    #+#              #
#    Updated: 2022/10/14 21:01:42 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src

NAME = rt

SRC = main.c camera.c ray.c color.c sphere.c material.c objectlist.c vec3.c vector.c

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = gcc
CFLAGS = -Wall -std=c11 -O3
RM = rm -r
RMF = rm -rf

all: ${NAME}

${NAME} : ${OBJ}
	@${CC} ${OBJ} -o ${NAME}
	@echo "rt is compiled"
	
obj/%.o: %.c | obj
	@${CC} ${CFLAGS} -c $< -o $@ 

obj:
	@mkdir obj

clean:
	@${RMF} obj
	@echo "object files are deleted"

fclean: clean
	@${RM} ${NAME}
	@echo "executable is deleted"
	@${RM} image.ppm
	@echo "image is deleted"

re: fclean all

image: ${NAME}
	./${NAME} > image.ppm

.PHONY:	all clean fclean re image