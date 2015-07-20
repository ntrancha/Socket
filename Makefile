all:
	@cd bin/libft/;make re
	@cd bin/; make re

install:all
	@mv bin/client .
	@mv bin/server .
	@echo "Done"

clean:
	@cd bin/; make clean
	@rm -rf server client

re:clean install
