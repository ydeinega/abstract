NAME	= 	avm

FLAGS	= 	-Wall -Wextra -Werror -std=c++11
SRC		=	Avm.Class.cpp \
			main.cpp \
			AvmException.Class.cpp \
			Factory.Class.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@g++ $(FLAGS) $(OBJ) -o $(NAME)
			@echo "avm compiled"

$(OBJ):
			@g++ -c $(FLAGS) $(SRC)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -f $(NAME)
			@echo "fclean"

re:			fclean all