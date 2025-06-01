## Commands ##
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -I./ -g ##-fsanitize=address
LDFLAGS = -L./libft -lft
RM = rm -f
MKDIR = mkdir -p

## Files ##
SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c

# Derive object files separately
SERVER_OBJS = $(SERVER_SRCS:src/%.c=obj/%.o)
CLIENT_OBJS = $(CLIENT_SRCS:src/%.c=obj/%.o)

OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)
DEPS = $(OBJS:.o=.d)


all: server client

server: obj $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LDFLAGS)

client: obj $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LDFLAGS)


obj:
	@$(MKDIR) obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	$(RM) -r obj
	$(MAKE) -C libft clean

fclean: clean
	$(RM) server client 
	$(MAKE) -C libft fclean

re: fclean all

libft: libft/libft.a

libft/libft.a:
	$(MAKE) -C libft all

.PHONY: all clean fclean re server client libft
