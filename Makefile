EX = demo

all:
	g++ main.cpp src/* -o $(EX) -I include -L lib -l SDL2-2.0.0

clean:

fclean: clean
	rm -rf $(EX)

re: fclean all

.PHONY: all clean fclean re
