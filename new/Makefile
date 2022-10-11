# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 09:01:25 by kanykei           #+#    #+#              #
#    Updated: 2022/10/11 16:28:53 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	src
NAME = rtObject

SRC = main.c color.c vec3.c camera.c ray.c sphere.c objectlist.c vector.c

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
HEADERS = *.h
RM = rm -r
RMF = rm -rf

all: ${NAME}

${NAME} : ${OBJ} ${HEADERS}
	@${CC} ${OBJ} -o ${NAME} -fsanitize=address
	@echo "rtObject is compiled"
	
obj/%.o: %.c | obj
	@${CC} ${CFLAGS} -c $< -o $@ 

obj:
	@mkdir obj

clean:
	@${RMF} obj
	@echo "\033[1;32m object files deleted \033[0m"

fclean: clean
	@${RM} ${NAME}
	@${RM} image.ppm
	@echo "\033[1;32m executable deleted \033[0m"

re: fclean all

image: ${NAME}
	./${NAME} > image.ppm

.PHONY:	all clean fclean re image