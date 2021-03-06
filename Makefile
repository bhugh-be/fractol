# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 17:26:57 by bhugh-be          #+#    #+#              #
#    Updated: 2019/05/28 15:25:45 by bhugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

LIB_MLX =  -lmlx -framework OpenGL -framework Appkit

LIB_OPENCL = -framework OpenCL

LIB_PATH = ./libft

LIB = ./libft/libft.a

SRC  =	fractol.c\
		mousehooks.c\
		keyhooks.c\
		cl_open.c\

INCLUDES = -I ./includes -I ./libft/includes

OBJ_DIR = ./objs

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC_DIR = ./srcs

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ)
			@make -C $(LIB_PATH)
			@gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(INCLUDES) $(LIB_MLX) $(LIB_OPENCL)

clean:
			@make clean -C $(LIB_PATH)
			@rm -rf $(OBJ_DIR)

fclean: clean
			@make fclean -C $(LIB_PATH)
			@rm -f $(NAME)

re: fclean all
