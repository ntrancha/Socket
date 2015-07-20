NAME_SERVER = server
NAME_CLIENT = client
SYS = sys.c
FILES_SERVER = main_server.c
FILES_CLIENT = main_client.c

all: CREATE_CLIENT CREATE_SERVER
	@echo "COMPILATION DONE"

CREATE_CLIENT:
	@gcc $(FILES_SERVER) $(SYS) libft/libft.a -Ilibft/includes/ -g -o $(NAME_SERVER)

CREATE_SERVER:
	@gcc $(FILES_CLIENT) $(SYS) libft/libft.a -Ilibft/includes/ -g -o $(NAME_CLIENT)

clean:
	@rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re: clean all
