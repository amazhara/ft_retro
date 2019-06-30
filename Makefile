NAME = ft_retro
FLAGS = -Wall -Wextra -Werror
NCURS = -lncurses
SRC_PATH = src
SRC_FILES = AProperties.cpp Enemy.cpp EnemyShot.cpp main.cpp Player.cpp shot.cpp Sky.cpp map.cpp

SRC_FULL = $(patsubst %.cpp, $(SRC_PATH)/%.cpp, $(SRC_FILES))
OBJECTS = $(patsubst %.cpp, $(SRC_PATH)/%.o, $(SRC_FILES))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	clang++ -o $(NAME) $(SRC_FULL) $(FLAGS) $(NCURS) $(LIBRARI)

%.o: $(SRC_PATH)/%.cpp
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	