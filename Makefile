# Makefile

NAME_SERVER = server
NAME_CLIENT = client

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS = $(SRC_DIR)/client.c $(SRC_DIR)/server.c
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(SRC_DIR) -I$(LIBFT_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJ_DIR)/client.o $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFT_A)

$(NAME_SERVER): $(OBJ_DIR)/server.o $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFT_A)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re
