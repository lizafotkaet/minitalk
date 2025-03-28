CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -g
RM = rm -f

SRCS_SERVER = server.c \

SRCS_CLIENT = client.c \

# Added OBJDIR variable for object files directory
OBJDIR = obj
# Updated OBJS variable to include the directory
OBJS_SERVER = $(addprefix $(OBJDIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(OBJDIR)/, $(SRCS_CLIENT:.c=.o))

NAME_SERVER = server
NAME_CLIENT = client

## Compilation server ##
$(NAME_SERVER): $(OBJS_SERVER) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) -Llibft -lft

## Compilation client ##

$(NAME_CLIENT): $(OBJS_CLIENT) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) -Llibft -lft

# Updated compilation rule to place .o files in the OBJDIR
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

## Cleaning ##
clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)
	$(RM) -r $(OBJDIR) # Remove the object files directory
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)
	$(MAKE) -C libft fclean

re: fclean $(NAME)

## Ensure libft is built ##
libft/libft.a:
	$(MAKE) -C libft all

